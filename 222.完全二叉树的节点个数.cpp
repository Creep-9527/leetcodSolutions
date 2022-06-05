/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
struct TreeNode
{
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
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int leftDepth = 0, rightDepth = 0;
        TreeNode *left = root->left, *right = root->right;
        while(left!=nullptr){
            ++leftDepth;
            left = left->left;
        }
        while(right!=nullptr){
            ++rightDepth;
            right = right->right;
        }
        if(leftDepth == rightDepth){
            return (2 << leftDepth) - 1;
        }
        else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
// @lc code=end

