// Maximum Depth of Binary Tree

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return (l > r ? l : r) + 1;
}