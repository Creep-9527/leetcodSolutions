/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */
#include<stack>
using namespace std;
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
    TreeNode* leftNext(stack<TreeNode*>& s) {
        TreeNode* root = s.top();
        s.pop();
        TreeNode* cur = root->right;
        while (cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        }
        return root;
    }
    TreeNode* rightNext(stack<TreeNode*>& s) {
        TreeNode* root = s.top();
        s.pop();
        TreeNode* cur = root->left;
        while (cur != nullptr) {
            s.push(cur);
            cur = cur->right;
        }
        return root;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* left = root, * right = root;
        stack<TreeNode*>leftStack, rightStack;
        leftStack.push(left);
        while (left->left != nullptr) {
            left = left->left;
            leftStack.push(left);
        }
        rightStack.push(right);
        while (right->right != nullptr) {
            right = right->right;
            rightStack.push(right);
        }
        while (left != right) {
            if (left->val + right->val == k) {
                return true;
            }
            if (left->val + right->val < k) {
                left = leftNext(leftStack);
            }
            else {
                right = rightNext(rightStack);
            }
        }
        return false;
    }
};
// @lc code=end

