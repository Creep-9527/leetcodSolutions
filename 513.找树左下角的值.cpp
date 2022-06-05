/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */
#include<algorithm>
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
    int maxLeftLen = INT_MIN;
    int leftVal;
    void traversal(TreeNode* root,int leftLen){
        if(root->left == nullptr && root->right == nullptr){
            if(leftLen> maxLeftLen){
                maxLeftLen = leftLen;
                leftVal = root->val;
            }
            return;
        }
        if(root->left!=nullptr){
            ++leftLen;
            traversal(root->left, leftLen);
            --leftLen;
        } 
        if(root->right!=nullptr){
            ++leftLen;
            traversal(root->right, leftLen);
            --leftLen;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return leftVal;
    }
};
// @lc code=end

