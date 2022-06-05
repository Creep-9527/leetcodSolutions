struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val <= p->val) {
        return inorderSuccessor(root->right, p);
    }
    else {
        TreeNode* node = inorderSuccessor(root->left, p);
        return node == nullptr ? root : node;
    }
}