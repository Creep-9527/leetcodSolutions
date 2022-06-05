/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    vector<int> pre;
    vector<int> ino;
    TreeNode *build(int preSta,int preEnd,int inoSta,int inoEnd){
        if(preSta>preEnd || inoSta>inoEnd){
            return nullptr;
        }
        int rootVal = pre[preSta];
        TreeNode *root = new TreeNode(rootVal);
        int rootInd = inoSta;
        while(rootInd<=inoEnd && ino[rootInd] != rootVal){
            ++rootInd;
        }
        int leftLen = rootInd - inoSta;
        int rightLen = inoEnd - rootInd;
        root->left = build(preSta + 1, preSta + leftLen, inoSta, rootInd - 1);
        root->right = build(preSta + leftLen + 1, preEnd, rootInd + 1, rootInd + rightLen);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        int n = preorder.size();
        this->pre = preorder;
        this->ino = inorder;
        return build(0, n - 1, 0, n - 1);
    }
};
// @lc code=end

