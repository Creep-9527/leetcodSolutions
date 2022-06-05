/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
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
    vector<int> ino;
    vector<int> post;
    TreeNode* build(int inoSta,int inoEnd,int postSta,int postEnd){
        if(inoSta>inoEnd || postSta > postEnd){
            return nullptr;
        }
        int rootVal = post[postEnd];
        int rootInd = inoSta;
        TreeNode *root = new TreeNode(rootVal);
        while(rootInd<=inoEnd && ino[rootInd] != rootVal){
            ++rootInd;
        }
        int leftLen = rootInd - inoSta;
        int rightLen = inoEnd - rootInd;
        root->left = build(inoSta, rootInd - 1, postSta, postSta + leftLen - 1);
        root->right = build(rootInd + 1, inoEnd, postSta + leftLen, postEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->ino = inorder;
        this->post = postorder;
        int n = inorder.size();
        return build(0, n - 1, 0, n - 1);
    }
};
// @lc code=end

