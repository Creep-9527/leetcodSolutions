/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include<algorithm>
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
    TreeNode* pre = nullptr;
    int minDis = INT_MAX;
    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        if (pre != nullptr) {
            minDis = min(minDis, abs(root->val - pre->val));
        }
        pre = root;
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minDis;
    }
};
// @lc code=end

