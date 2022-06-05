/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */
#include<string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode* cur, string& s) {
        if (cur == nullptr) {
            s.append("()");
            return;
        }
        bool empty = s.empty();
        if (empty) {
            s.append(to_string(cur->val));
        }
        else {
            s.push_back('(');
            s.append(to_string(cur->val));
        }
        if (!(cur->left == nullptr && cur->right == nullptr)) {
            traversal(cur->left, s);
            if (cur->right != nullptr) {
                traversal(cur->right, s);
            }
        }
        if (!empty) {
            s.push_back(')');
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string ans;
        if (root == nullptr) {
            return ans;
        }
        traversal(root, ans);
        return ans;
    }
};
// @lc code=end

