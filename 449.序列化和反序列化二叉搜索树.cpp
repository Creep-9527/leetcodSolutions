/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */
#include<string>
#include<vector>
#include<stack>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Codec {
 public:
     static string strTree;
     void postOrder(TreeNode* root, vector<int>& list) {
         if (root == nullptr) {
             return;
         }
         postOrder(root->left,list);
         postOrder(root->right, list);
         list.emplace_back(root->val);
         return;
     }
     TreeNode* construct(int low, int up, stack<int>& st) {
         if (st.size() == 0 || st.top() < low || st.top() > up) {
             return nullptr;
         }
         int val = st.top();
         TreeNode* root = new TreeNode(val);
         st.pop();
         root->right = construct(val, up, st);
         root->left = construct(low, val, st);
         return root;
     }
     // Encodes a tree to a single string.
     string serialize(TreeNode* root) {
         string str;
         if (root == nullptr) {
             return str;
         }
         vector<int>list;
        postOrder(root, list);
        for (int i = 0; i < list.size() - 1; i++) {
            str += to_string(list[i]) + ',';
        }
        str += to_string(list.back());
        return str;
    }

    // Decodes your encoded data to tree.
     TreeNode* deserialize(string data) {
         if (data.empty()) {
             return nullptr;
         }
         stack<int>st;
        int cur = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] != ',') {
                cur *= 10;
                cur += data[i] - '0';
            }
            else {
                st.push(cur);
                cur = 0;
            }
        }
        st.push(cur);
        return construct(INT_MIN, INT_MAX, st);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

