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

int count = 0;

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
            count++;
        }
        else
        {
            rear->next = newnode;
            rear=newnode;
            rear->next=front;
            count++;
        }
        printf("Inserted element %d\n",data);
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("Empty Queue \n");
    }
    else if(front==rear)
    {
        printf("Deleted %d \n",front->data);
        front=NULL;
        rear=NULL;
        count--;
    }
    else
    {
        struct node *temp;
        temp=front;
        front=front->next;
        rear->next=front;
        printf("Deleted %d \n",temp->data);
        free(temp);
        count--;
    }
}
void display()
{
    struct node *temp;
    temp=front;
    if(front==NULL)
    {
        printf("Empty Queue \n");
    }
    else
    {
    for(int i=1;i<=count;i++)
    {
        printf("%d |",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}