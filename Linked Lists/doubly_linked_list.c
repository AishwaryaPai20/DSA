#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
}*head,*end;

int i;
void createLinkedList();
void insertAtBeginning();
void insertAtEnd();
void insertAtMiddle();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtMiddle();
void forwardtraversing();
void reversetraversing();

void createLinkedList()
{
    int data,n;
    struct node *temp;
    printf("Enter the number of elements to insert\n");
    scanf("%d",&n);
    printf("Enter the element you want to insert at 1 \n");
    scanf("%d",&data);
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Error \n");
    }
    else
    {
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        temp=head;
        printf("Inserted %d\n",data);
        for(int i=2;i<=n;i++)
        {
            printf("Enter the element you want to enter at %d\n",i);
            scanf("%d",&data);
            struct node *newnode;
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            newnode->prev=temp;
            newnode->next=NULL;
            temp->next=newnode;
            temp=newnode;
            printf("Inserted %d\n",data);
        }
        end=temp;
    }
}
void insertAtBeginning()
{
    int data;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to enter at the beginning \n");
    scanf("%d",&data);
    if(newnode==NULL)
    {
        printf("Error \n");
    }
    else
    {
        newnode->data=data;
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
        printf("Inserted %d at the beginning \n",data);
    }
}
void insertAtEnd()
{
    int data;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert at the end \n");
    scanf("%d",&data);
    if(newnode==NULL)
    {
        printf("Error \n");
    }
    else
    {
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=end;
        end->next=newnode;
        end=newnode;
        printf("Inserted %d at the end\n",data);
    }
}
void insertAtMiddle()
{
    int data,position;
    struct node *newnode,*temp;
    printf("Enter the position you want to insert \n");
    scanf("%d",&position);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert \n");
    scanf("%d",&data);
    temp=head;
    if(newnode==NULL)
    {
        printf("Error \n");
    }
    else
    {
        for(int i=1;i<=position-1;i++)
        {
            temp=temp->next;
        }
        newnode->data=data;
        newnode->next=temp;
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;
        printf("Inserted %d at the position %d\n",data,position);
    }
}
void deleteAtBeginning()
{
    struct node *temp;
    temp=head;
    head=head->next;
    head->prev=NULL;
    printf("Deleted %d from the beginning\n",temp->data);
    free(temp);
}
void deleteAtEnd()
{
    struct node *temp;
    temp=end;
    end=end->prev;
    end->next=NULL;
    free(temp);
    printf("Deleted %d from the end\n",temp->data);
}
void deleteAtMiddle()
{
    int position;
    printf("Enter the position you want to delete the element \n");
    scanf("%d",&position);
    struct node *temp,*temp1;
    temp=head;
    for(int i=1;i<=position-1;i++)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next->prev=temp1;
    free(temp);
    printf("Deleted %d from position %d\n",temp->data,position);
}
void forwardtraversing()
{
    struct node *temp;
    temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reversetraversing()
{
    struct node *temp;
    temp=end;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
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
        printf("7. Forward Traversing\n");
        printf("8. Reverse Traversing\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                insertAtBeginning();
                forwardtraversing();
                break;
            }
            case 2:
            {
                insertAtMiddle();
                forwardtraversing();
                break;
            }
            case 3:
            {
                insertAtEnd();
                forwardtraversing();
                break;
            }
            case 4:
            {
                deleteAtBeginning();
                forwardtraversing();
                break;
            }
            case 5:
            {
                deleteAtMiddle();
                forwardtraversing();
                break;
            }
            case 6:
            {
                deleteAtEnd();
                forwardtraversing();
                break;
            }
            case 7:
            {
                forwardtraversing();
                break;
            }
            case 8:
            {
                reversetraversing();
                break;
            } 
        }
        printf("\nDo you want to exit ? enter 0 for no or 1 for yes \n");
        scanf("%d",&exit);
    }
    return 0;
}