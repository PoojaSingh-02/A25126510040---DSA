int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    if (root == NULL) {
        return result;
    }
    int* left = inorderTraversal(root->left, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        result[i] = left[i];
    }
    result[*returnSize] = root->val;
    (*returnSize)++;
    int rightSize = 0;
    int* right = inorderTraversal(root->right, &rightSize);
    for (int i = 0; i < rightSize; i++) {
        result[*returnSize] = right[i];
        (*returnSize)++;
    }
    return result;
}
