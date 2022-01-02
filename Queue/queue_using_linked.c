#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *next;
}*front,*rear;
void enqueue();
void dequeue();
void display();

int main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    display();
    return 0;
}
void enqueue()
{
    int data;
    struct node *newnode;
    printf("Enter the element you want to add \n");
    scanf("%d",&data);
    newnode = (struct node *) malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Error");
    }
    else
    {
        newnode->data =data;
        newnode->next = NULL;
        if(front==NULL)
        {
            front=rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear=newnode;
        }
        printf("Inserted element %d\n",data);
    }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    front=front->next;
    printf("Deleted element %d\n",temp->data);
    free(temp);
}
void display()
{
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("|%d|",temp->data);
        temp=temp->next;
    }
    printf("\n");
}