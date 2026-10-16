
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    int value;
    struct Node *newNode, *last;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    printf("Node inserted successfully\n");
}

void deleteNode() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Circular DLL: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete first node\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

<img width="557" height="517" alt="image" src="https://github.com/user-attachments/assets/c21ffc21-9be2-49ef-a2a6-cce9161ca4ad" />
<img width="656" height="607" alt="image" src="https://github.com/user-attachments/assets/31e1c5d7-4ce4-419e-9fcb-2dd082e738a0" />
<img width="325" height="167" alt="image" src="https://github.com/user-attachments/assets/64c21348-6ee3-4d23-a09e-d574fa8ffc7d" />



    return 0;
}
