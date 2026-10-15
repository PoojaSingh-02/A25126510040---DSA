class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};


<img width="520" height="117" alt="image" src="https://github.com/user-attachments/assets/90d9b91a-f132-4f2e-9ade-acbd071ac089" />
