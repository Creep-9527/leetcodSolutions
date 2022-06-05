/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int target;
    bool traversal(TreeNode* root,int cur){
        if(root == nullptr){
            return false;
        }
        cur += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(cur == target){
                return true;
            }
            else{
                return false;
            }
        }
        if(root->left != nullptr){
            if(traversal(root->left,cur)){
                return true;
            }
        }
        if(root->right != nullptr){
            if(traversal(root->right,cur)){
                return true;
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return traversal(root, 0);

    }
};
// @lc code=end

