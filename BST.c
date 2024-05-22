// Binary search tree in c implementation
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data= x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
} 

void inorder(struct Node* root)
{
    if (root == NULL)
        return;
    inorder(root -> left);
    printf("%d", root->data);
    inorder(root -> right);
    return;
}

void preorder(struct Node* root)
{
    if (root == NULL)
        return;

    printf("%d", root->data);
    preorder(root -> left);
    preorder(root -> right);
    return;
}

void postorder(struct Node* root)
{
    if (root == NULL)
        return;

    postorder(root -> left);
    postorder(root -> right);
    printf("%d", root->data);
    return;
}

int main()
{
    struct Node* root = NULL;

    root = createNode(2);
    root ->left =  createNode(7);
    root->right = createNode(5);
    root->left->left = createNode(2);
    root->left->right = createNode(6);
    root->left->right->left = createNode(5);
    root -> left->right->right = createNode(11);
    root -> right ->right = createNode(9);
    root -> right -> right ->left = createNode(4);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}
