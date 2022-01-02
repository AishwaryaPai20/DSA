#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *createnode();  //in this struct function the pointer returns
void preorder(struct node *root);   //data->left->right
void postorder(struct node *root);  //left->right->data
void inorder(struct node *root);   //left->data->right
void deletenode(struct node *root);

int main()
{
    struct node *root;
    root=createnode();
    root->left=createnode();
    root->right=createnode();
    root->left->left=createnode();
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    deletenode(root->left);
    return 0;
}

struct node *createnode()
{
    int data;
    struct node *newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("Enter the data you want to insert \n");
    scanf("%d", &data);
    newnode->data = data;
    newnode->left =NULL;
    newnode->right =NULL;
    printf("Inserted %d\n",data);
    return newnode;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d -> ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ",root->data);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d -> ",root->data);
        inorder(root->right);
    }
}
void deletenode(struct node *root)
{
    if(root!=NULL)
    {
        deletenode(root->left);
        deletenode(root->right);
        printf("Deleted %d\n",root->data);
        free(root);
    }
}