//Search operation in BST
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d" , root->data);
    inorder(root->right);
}

struct Node* insert(struct Node* root, int data)
{
    if(root == NULL){
        return createNode(data);
    }
    if (data < root->data )
    {
        root ->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right,data);
    }
    return root;
      
}

struct Node* search(struct Node* root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return search(root->right,data);
    
    return search(root->left,data);
    
}

int main(){
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    int data = 1;
    if (search(root, data) == NULL)
    {
        printf("%d not found\n", data);
    }
    else
    {
        printf("%d found\n", data);
    }
    data = 40;

    if (search(root, data) == NULL)
    {
        printf("%d not found\n", data);
    }
    else
    {
        printf("%d found\n", data);
    }


    return 0;
}