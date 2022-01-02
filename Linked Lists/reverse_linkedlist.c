#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*head;

void createLinkedList()
{
    int data,n,i;
    struct node *newnode,*temp;
    printf("Enter the number of elements you want to add to the list: \n");
    scanf("%d",&n);
    head=(struct node *)malloc(sizeof(struct node)); //typecast to struct node
    if(head==NULL)
    {
        printf("Unable to create the Linked List ");
    }
    else
    {
        printf("Enter the element at node 1 : \n");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        printf("Node inserted at 1 \n");
    }
    for(i=2;i<=n;i++)
    {
        printf("Enter the element at node %d : \n",i);
        scanf("%d",&data);
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Error!");
        }
        else
        {
            newnode->data=data;
            newnode->next=NULL;
            temp->next=newnode;
            temp=newnode;
            printf("Node inserted at %d \n",i);
        }
    }
}
void Reverse()
{
    struct node *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is Empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d - >",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    createLinkedList();
    display();
    printf("\n");
    Reverse();
    display();
}