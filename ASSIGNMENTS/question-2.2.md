#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Overflow: queue is full, cannot insert %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted %d at position %d\n", value, rear);
}

void dequeue() {
    if (isEmpty()) {
        printf("Underflow: queue is empty, nothing to delete\n");
        return;
    }
    printf("Deleted %d from position %d\n", queue[front], front);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n[front = %d, rear = %d]\n", front, rear);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
}


<img width="365" height="582" alt="image" src="https://github.com/user-attachments/assets/21c90d18-00e1-44f3-865e-dc6cf673135d" />
<img width="477" height="545" alt="image" src="https://github.com/user-attachments/assets/6851cca7-dcec-4ec2-b034-203c624ede22" />
<img width="427" height="447" alt="image" src="https://github.com/user-attachments/assets/19fb9f96-78a7-46cf-a28b-1f82a9526a75" />

