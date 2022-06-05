/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include<string>
#include<vector>
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
    vector<string> pathList;
    vector<int> path;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr){
            return pathList;
        }
        path.push_back(root->val);
        if(root->left != nullptr){
            binaryTreePaths(root->left);
        }
        if(root->right != nullptr){
            binaryTreePaths(root->right);
        }
        if(root->left == nullptr && root->right == nullptr){
            string sPath;
            for (int i = 0; i < path.size() - 1; ++i){
                sPath += to_string(path[i]) + "->";
            }
            sPath += to_string(path.back());
            pathList.push_back(sPath);
        }
        path.pop_back();
        return pathList;
    }
};
// @lc code=end

