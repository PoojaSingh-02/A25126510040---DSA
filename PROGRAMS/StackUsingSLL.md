#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node*top=NULL;

struct Node*createNode(int value)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->next=NULL;

    return newNode;
}

void push(int value)
{
    struct Node*newNode=createNode(value);

    newNode->next=top;
    top=newNode;

    printf("%d pushed into stack\n",value);
}

void pop()
{
    struct Node*temp;

    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp=top;

    printf("Popped element:%d\n",top->data);

    top=top->next;

    free(temp);
}

void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element:%d\n",top->data);
}

void displayList()
{
    struct Node*temp=top;

    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value:");
                scanf("%d",&value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                displayList();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }


    <img width="660" height="547" alt="image" src="https://github.com/user-attachments/assets/774713a1-7b4c-4bca-8f4b-3af67e5eb636" />
    <img width="660" height="627" alt="image" src="https://github.com/user-attachments/assets/6d80549b-946a-4b92-b25a-e598826294ab" />
    <img width="497" height="251" alt="image" src="https://github.com/user-attachments/assets/bacc6f14-95c7-4079-942d-3133746f0075" />




    return 0;
}
