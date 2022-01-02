#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
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

bool isFullBinaryTree(struct node *root) 
{
  // Checking tree emptiness
    if (root == NULL)
        return true;

    // Checking the presence of children
    if (root->left == NULL && root->right == NULL)
        return true;

    if ((root->left) && (root->right))
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

    return false;
}
int main() {
    struct node *root;
    root=createnode();
    root->left=createnode();
    root->right=createnode();
    root->left->left=createnode();
    root->left->right=createnode();
    if (isFullBinaryTree(root))
        printf("The tree is a full binary tree\n");
    else
        printf("The tree is not a full binary tree\n");
}