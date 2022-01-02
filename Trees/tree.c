#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
    // if(isBinarySearchTree(root,INT_MIN,INT_MAX)) 
    // printf("It is Binary Search Tree \n");
    // else  printf("It is not a Binary Search Tree \n");
    // return 0;
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
// bool IsSubtreeLesser(struct node *root,int value);
// bool IsSubtreeGreater(struct node *root,int value);

// bool IsBinarySearchTree(struct node *root)
// {
//     if(root==NULL) return true;
//     if(IsSubtreeLesser(root->left,root->data)&&IsSubtreeGreater(root->right,root->data)&&IsBinarySearchTree(root->left)&&IsBinarySearchTree(root->right))
//     return true;
//     else 
//     return false;
// }

// bool IsSubtreeLesser(struct node *root,int value)
// {
//     IF(root==NULL) return true;
//     if(root->data<=value&&IsSubtreeLesser(root->left,value)&&IsSubtreeLesser(root->right,value))
//     return true;
//     else 
//     return false;
// }
// bool IsSubtreeGreater(struct node *root,int value)
// {
//     IF(root==NULL) return true;
//     if(root->data<=value&&IsSubtreeGreater(root->left,value)&&IsSubtreeGreater(root->right,value))
//     return true;
//     else 
//     return false;
// }

// bool IsBinarySearchTree(struct node *root,int minValue, int maxValue)
// {
//     if(root==NULL) return true;
//     if(root->data>minValue&&root->data<maxValue&&IsBinarySearchTree(root->left,minValue,root->data)&&IsBinarySearchTree(root->right,root->data,maxValue))
//     return true;
//     else return false;
// }