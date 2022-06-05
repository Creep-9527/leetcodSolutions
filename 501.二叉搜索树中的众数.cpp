/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int maxCount;
    int count;
    vector<int>ans;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        if (pre != nullptr) {
            if (root->val == pre->val) {
                ++count;
                if (count == maxCount) {
                    ans.push_back(root->val);
                }
                else if (count > maxCount) {
                    maxCount = count;
                    ans.clear();
                    ans.push_back(root->val);
                }
            }
            else {
                count = 1;
                if (count == maxCount) {
                    ans.push_back(root->val);
                }
            }
        }
        else {
            count = 1;
            maxCount = 1;
            ans.push_back(root->val);
        }
        pre = root;
        traversal(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return ans;
    }
};
// @lc code=end

