
#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push() {
    int value;

    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Element pushed successfully\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
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


<img width="696" height="537" alt="image" src="https://github.com/user-attachments/assets/b65b50bc-bec5-438e-bfd1-4c9a2c21a687" />
<img width="726" height="605" alt="image" src="https://github.com/user-attachments/assets/5f267a2d-008f-4320-a8da-acd9f679d288" />


    return 0;
}
