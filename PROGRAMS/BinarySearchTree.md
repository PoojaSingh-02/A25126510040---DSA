#include <stdio.h>
#include <stdlib.h>

/* BST Node */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

/* Create new node */
struct Node *createNode(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert into BST */
struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value not allowed!\n");

    return root;
}

/* Inorder: Left, Root, Right */
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder: Root, Left, Right */
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder: Left, Right, Root */
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search a value */
struct Node *search(struct Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

/* Find largest node in left subtree */
struct Node *findLargestInLeftSubtree(struct Node *root) {
    if (root == NULL || root->left == NULL)
        return NULL;

    struct Node *temp = root->left;

    while (temp->right != NULL)
        temp = temp->right;

    return temp;
}

/* Delete a node */
struct Node *deleteNode(struct Node *root, int value) {
    if (root == NULL) {
        printf("Value not found!\n");
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        /* Case 1: No child */
        if (root->left == NULL &&
            root->right == NULL) {
            free(root);
            return NULL;
        }

        /* Case 2: Only right child */
        else if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        /* Case 3: Only left child */
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        /* Case 4: Two children */
        else {
            struct Node *temp =
                findLargestInLeftSubtree(root);

            root->data = temp->data;

            root->left =
                deleteNode(root->left, temp->data);
        }
    }

    return root;
}

/* Main function */
int main() {
    int choice, value;

    while (1) {
        printf("\n\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Find Largest in Left Subtree\n");
        printf("7. Delete\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value) != NULL)
                    printf("Value found!\n");
                else
                    printf("Value not found!\n");
                break;

            case 6: {
                struct Node *temp =
                    findLargestInLeftSubtree(root);

                if (temp != NULL)
                    printf("Largest in left subtree: %d\n",
                           temp->data);
                else
                    printf("Left subtree is empty!\n");
                break;
            }

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}


<img width="817" height="680" alt="image" src="https://github.com/user-attachments/assets/0406f487-c3f4-4535-95cd-6e2f94edd022" />
<img width="822" height="492" alt="image" src="https://github.com/user-attachments/assets/bc2f643e-8cf9-4204-aaff-ad710ab42f4a" />
<img width="665" height="621" alt="image" src="https://github.com/user-attachments/assets/ada5cf30-03de-437f-8749-45cb6bd793c0" />
<img width="647" height="440" alt="image" src="https://github.com/user-attachments/assets/0cb49e3a-4c8c-4132-b1d2-dd083b83983f" />
<img width="625" height="615" alt="image" src="https://github.com/user-attachments/assets/0174b852-191e-4772-ab72-71bba408292a" />
<img width="712" height="626" alt="image" src="https://github.com/user-attachments/assets/780d57e4-94b8-4e26-8fd4-dd0ce3d1c353" />
<img width="642" height="591" alt="image" src="https://github.com/user-attachments/assets/f04e18e1-5076-40f2-b587-4aeb4b1228be" />
<img width="410" height="300" alt="image" src="https://github.com/user-attachments/assets/c8c366ea-2b2a-44ad-b35d-829642f18f31" />



