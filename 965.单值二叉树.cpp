/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    bool helper(TreeNode* root, int val) {
        if (root == nullptr) {
            return true;
        }
        if (root->val != val) {
            return false;
        }
        return helper(root->left, val) && helper(root->right, val);
    }
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int val = root->val;
        return helper(root->left, val) && helper(root->right, val);
    }
};
// @lc code=end

