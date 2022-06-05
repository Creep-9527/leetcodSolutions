/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <vector>
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
    TreeNode *build(vector<int> &nums, int left, int right) {
        if(left>right){
            return nullptr;
        }
        int maxVal = nums[left];
        int maxInd = left;
        for (int i = maxInd + 1; i <= right; ++i){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                maxInd = i;
            }
        }
        TreeNode *root = new TreeNode(maxVal);
        root->left = build(nums, left, maxInd - 1);
        root->right = build(nums, maxInd + 1, right);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        int n = nums.size();
        return build(nums, 0, n - 1);
    }
};
// @lc code=end
