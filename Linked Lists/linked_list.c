#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*head;

int i;
void createLinkedList();
void insertAtBeginning();
void insertAtMiddle();
void insertAtEnd();
void deleteAtBeginning();
void deleteAtMiddle();
void deleteAtEnd();
void len();
void display();

void createLinkedList()
{
    int data,n;
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
void insertAtBeginning()
{
    int data;
    struct node *newnode1,*temp;
    printf("Enter the element to be inserted at beginning : \n");
    scanf("%d",&data);
    newnode1=(struct node *)malloc(sizeof(struct node));
    if(newnode1==NULL)
    {
        printf("Error");
    }
    else
    {
        newnode1->data=data;
        newnode1->next=head;
        head=newnode1;
        printf("Node has been inserted at the beginning \n");
    }
}
void insertAtMiddle()
{
    int position,data;
    struct node *newnode,*temp;
    printf("Enter the position u want to insert the element : \n");
    scanf("%d",&position);
    printf("Enter the element to be inserted : \n");
    scanf("%d",&data);
    newnode=(struct node *)malloc(sizeof(struct node));
    if(position<2)
    {
        insertAtBeginning();
    }
    else
    {
        newnode->data=data;
        temp=head;
        for(int i=0;i<position-2;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    
}
void insertAtEnd()
{
    int data;
    struct node *newnode,*temp;
    printf("Enter the element you want to insert at the end : \n");
    scanf("%d",&data);
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Error :");
    }
    else
    {
    newnode->data=data;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    }
}
void deleteAtBeginning()
{
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    printf("Deleted first node!\n");
}
void deleteAtMiddle()
{
    int position;
    printf("Enter the position you want to delete \n");
    scanf("%d",&position);
    struct node *temp,*del;
    temp=head;
    for(int i=1;i<position-1;i++)
    {
        del=temp;
        temp=temp->next;
    }
    del->next=temp->next;
    free(temp);
}
void deleteAtEnd()
{
    struct node *temp,*last;
    temp=head;
    while(temp->next!=NULL)
    {
        last=temp;
        temp=temp->next;
    }
    last->next=NULL;
    free(temp);
    printf("Deleted last node!\n");
}
void len()
{
    int count;
    struct node *temp;
    temp=head;
    for(count=1;temp->next!=NULL;count++)
    {
        temp=temp->next;
    }
    printf("Total elements in the linked list are %d ",count);
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
    int choice;int exit=0;
    createLinkedList();
    while(exit!=1)
    {
        printf("Enter your choice : \n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Position\n");
        printf("6. Delete at End\n");
        printf("7. Length of the list\n");
        printf("8. Display List\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
                insertAtBeginning();
                display();
                break;
            }
            case 2: 
            {
                insertAtMiddle();
                display();
                break;
            }
            case 3: 
            {
                insertAtEnd();
                display();
                break;
            }
            case 4: 
            {
                deleteAtBeginning();
                display();
                break;
            }
            case 5: 
            {
                deleteAtMiddle();
                display();
                break;
            }
            case 6: 
            {
                deleteAtEnd();
                display();
                break;
            }
            case 7:
            {
                len();
                break;
            }
            case 8: 
            {
                display();
                break;
            }
        }
        printf("\nDo you want to exit ? enter 0 for no or 1 for yes \n");
        scanf("%d",&exit);
    }
    return 0;
}