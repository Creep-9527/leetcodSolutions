/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 */
#include<vector>
#include<stack>
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        stack<TreeNode*>s1, s2;
        while (root1 != nullptr || root2 != nullptr || !s1.empty() || !s2.empty()) {
            while (root1 != nullptr) {
                s1.push(root1);
                root1 = root1->left;
            }
            while (root2 != nullptr) {
                s2.push(root2);
                root2 = root2->left;
            }
            if (!s1.empty() && !s2.empty()) {
                if (s1.top()->val < s2.top()->val) {
                    root1 = s1.top();
                    s1.pop();
                    ans.emplace_back(root1->val);
                    root1 = root1->right;
                }
                else {
                    root2 = s2.top();
                    s2.pop();
                    ans.emplace_back(root2->val);
                    root2 = root2->right;
                }
            }
            else {
                if (!s1.empty()) {
                    root1 = s1.top();
                    s1.pop();
                    ans.emplace_back(root1->val);
                    root1 = root1->right;
                }
                else {
                    root2 = s2.top();
                    s2.pop();
                    ans.emplace_back(root2->val);
                    root2 = root2->right;
                }
            }
            
        }
        return ans;

    }
};
// @lc code=end

