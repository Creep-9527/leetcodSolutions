/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */
#include<vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 // @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>pre;
    void traversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        pre.push_back(root->val);
        for (auto& child : root->children) {
            traversal(child);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        traversal(root);
        return pre;
    }
};
// @lc code=end

