// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
struct node 
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) 
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// InOrder Traversal
void inOrder(struct node *root) 
{
    if (root != NULL) 
    {
    inOrder(root->left);
    printf("%d -> ", root->key);
    inOrder(root->right);
    }
}

// Insert a node
struct node *insert(struct node *node, int key) 
{
  // Return a new node if the tree is empty
    if (node == NULL) return newNode(key);

    // Traverse to the right place and insert the node
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Find the inOrder successor
struct node *minValueNode(struct node *node) 
{
struct node *current = node;

  // Find the leftmost leaf
while (current && current->left != NULL)
current = current->left;

return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
if (root == NULL) return root;
  // Find the node to be deleted
if (key < root->key)
    root->left = deleteNode(root->left, key);
else if (key > root->key)
    root->right = deleteNode(root->right, key);
else {
    // If the node is with only one child or no child
    if (root->left == NULL) 
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    } 
    else if (root->right == NULL) 
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }

    struct node *temp = minValueNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int search(struct node *root,int x)
{
    if (root == NULL)
    {
        return 0;
    }
    else if(root->key==x)
    {
        return 1;
    }
    else if(root->key>x)
    {
        return search(root->left,x);
    }
    else if(root->key<x)
    {
        return search(root->right,x);
    }
}
int FindMinValue(struct node *root)
{
    if(root == NULL) return 0;
    else if(root->left == NULL) return root->key;
    return FindMinValue(root->left);
}
int FindMaxValue(struct node *root)
{
    if(root == NULL) return 0;
    else if(root->right == NULL) return root->key;
    return FindMaxValue(root->right);
}
int FindHeight(struct node *root)
{
    if(root == NULL) return -1;
    int leftHeight=FindHeight(root->left);
    int rightHeight=FindHeight(root->right);
    return max(leftHeight,rightHeight)+1;
}
// Driver code
int main() 
{
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    printf("InOrder traversal: ");
    inOrder(root);

    printf("\nAfter deleting 3\n");
    root = deleteNode(root, 3);
    printf("InOrder traversal: ");
    inOrder(root);
    printf("\n");
    int y= search(root,7);
    if(y==1) printf("Element found \n");
    else printf("Element not found \n");
    printf("Minimum Value is %d\n",FindMinValue(root));
    printf("Maximum value is %d\n",FindMaxValue(root));
    printf("Height of the tree is %d\n",FindHeight(root));
}