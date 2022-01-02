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
    printf("Top %d \n",peek());
    display();
    push(5);
    printf("Top %d \n",peek());
    pop();
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
        printf("Pushed data %d\n",data);
    }
}
void pop()
{
    struct node *temp;
    temp=top;
    top=top->next;
    printf("Popped element %d",temp->data);
    free(temp);
}
int peek()
{
    return top->data;
}
void display()
{
    printf("\n");
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("|%d|",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
