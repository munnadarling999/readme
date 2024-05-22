//Insertion of nodes in BST
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void inorder(struct Node* root){
    if (root == NULL)
        return;
    
    inorder(root -> left);
    printf("%d", root->data);
    inorder(root -> right);
    return;
}

struct Node* insert(struct Node* root,int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root -> left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
  
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    return 0;
}