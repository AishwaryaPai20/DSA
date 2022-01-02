#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n)
{
    if(n == NULL) return 0;
    return n->height;
}

struct node *createNode(int key)
{
    struct node *node = malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}

int getBalanceFactor(struct node *n)
{
    if(n==NULL) return 0;
    else
    return getHeight(n->left)-getHeight(n->right);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
struct node* rightRotate(struct node* y)
{
    struct node* x=y->left;
    struct node *T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->left),getHeight(y->right));
    x->height=max(getHeight(x->left),getHeight(x->right));
    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y=x->right;
    struct node *T2=y->left;
    
    y->left=x;
    x->right=T2;

    y->height=max(getHeight(y->left),getHeight(y->right));
    x->height=max(getHeight(x->left),getHeight(x->right));
    return y;
}

struct node *insert(struct node* node,int key)
{
    if(node==NULL) return(createNode(key));
    if(key<node->key)
    node->left=insert(node->left,key);
    else if(key>node->key)
    node->right=insert(node->right, key);
    return node;

    node->height=1+max(getHeight(node->left),getHeight(node->right));
    int bf=getBalanceFactor(node);
    if(bf>1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    else if(bf<-1 && key > node->right->key) 
    {
        return leftRotate(node);
    }
    else if(bf>1 && key > node->left->key) 
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    else if(bf<-1 && key < node->right->key) 
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;                          
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d -> ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct node *root=NULL;
    root=insert(root,45);
    root=insert(root,37);
    root=insert(root,11);
    root=insert(root,32);
    root=insert(root,80);
    root=insert(root,5);
    root=insert(root,74);
    root=insert(root,21);
    root=insert(root,67);
    root=insert(root,56);
    preorder(root);   //
    return 0;
}

