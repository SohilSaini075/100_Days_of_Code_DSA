// Binary Tree Inorder Traversal


void inorder(struct TreeNode* root, int* arr, int* returnSize){
    if(root == NULL)
        return;

    inorder(root->left, arr, returnSize);

    arr[*returnSize] = root->val;
    (*returnSize)++;

    inorder(root->right, arr, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int* result = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}