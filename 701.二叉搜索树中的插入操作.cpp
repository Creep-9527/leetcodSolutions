/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (val < root->val) {
            if (root->left == nullptr) {
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return root;
            }
            else {
                insertIntoBST(root->left, val);
                return root;
            }
        }
        else {
            if (root->right == nullptr) {
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return root;
            }
            else {
                insertIntoBST(root->right, val);
                return root;
            }
        }
    }
};
// @lc code=end

