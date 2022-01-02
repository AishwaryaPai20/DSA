#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top;

void push(int data);
void pop();
int peek();
void display();

int main()
{
    push(4);
    push(3);
    push(5);
    display();
    return 0;
}
void push(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Error");
    }
    else
    {
        if(top == NULL)
        {
            newnode->data = data;
            newnode->next = NULL;
            top=newnode;
        }
        else
        {
            newnode->data = data;
            newnode->next=top;
            top = newnode;
        }
    }
}
void display()
{
    printf("\n");
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("%d||",temp->data);
        temp=temp->next;
    }
}
