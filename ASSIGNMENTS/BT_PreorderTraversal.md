void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    result[(*index)++] = root->val;
    preorder(root->left, result, index);
    preorder(root->right, result, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    *returnSize = 0;
    preorder(root, result, returnSize);
    return result;
}


<img width="467" height="116" alt="image" src="https://github.com/user-attachments/assets/a3a2edd3-1c9a-47a3-999b-ee6dac8aaced" />

