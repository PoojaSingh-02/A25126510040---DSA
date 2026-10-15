#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void enqueue();
void dequeue();
void display();

int queue_array[MAX];
int rear=-1;
int front=-1;

void enqueue()
{
    int add_item;

    if(rear==MAX-1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }

        printf("Insert the element in queue:");
        scanf("%d",&add_item);

        rear=rear+1;
        queue_array[rear]=add_item;
    }
}

void dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Queue underflow\n");
        return;
    }
    else
    {
        printf("Element deleted from queue is:%d\n",queue_array[front]);
        front=front+1;
        printf("Front value after deletion:%d\n",front);
    }
}

void display()
{
    int i;

    if(front==-1||front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is:\n");

        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue_array[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n*** MENU ***\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}



<img width="662" height="531" alt="image" src="https://github.com/user-attachments/assets/e9e5a0dd-35ae-47d3-9376-09bf01f03f13" />
<img width="567" height="457" alt="image" src="https://github.com/user-attachments/assets/9d5509af-b13d-4e30-a8d9-bede3341282c" />
<img width="747" height="452" alt="image" src="https://github.com/user-attachments/assets/86d62d81-a1ec-4935-924e-9e5db8f247d9" />



<img width="662" height="531" alt="image" src="https://github.com/user-attachments/assets/e1e1b826-3a35-473b-8d90-b2b1274e81ed" />
