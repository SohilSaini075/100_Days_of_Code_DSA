// Binary Tree Right Side View

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int* result = (int*)malloc(sizeof(int) * 100);
    
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            if (i == size - 1) {
                result[*returnSize] = curr->val;
                (*returnSize)++;
            }

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }

    return result;
}