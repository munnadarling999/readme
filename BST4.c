//Delete operation in BST
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
    temp -> data = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void inorder(struct Node* root)
{
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
    
}

struct Node * insert(struct Node* root, int data)
{
    if(root == NULL)
        return createNode(data);
    if (data < root->data)
    {
        root->left = insert(root->left,data);
    }
    else
    {
        root ->right = insert(root->right,data);
    }
    return root;
    
}

struct Node * deleteNode(struct Node* root, int k)
{
    if (root == NULL)
    {
        return root;
    }

    if(k < root->data)
    {
        root -> left = deleteNode(root->left, k);
        return root;
    }
    else if(k > root->data)
    {
        root -> right = deleteNode(root->right, k);
        return root;
    }

    //if the key is same as a root
    if (root->left == NULL)
    {
        struct Node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }

    struct Node* succParent = root;
    struct Node* succ = root->right;
    while(succ->left != NULL){
        succParent = succ;
        succ = succ->left;
    }

    root->data = succ->data;

    //Delete the inorder succesor
    if (succParent -> left == succ)
        succParent->left = succ->right;
    else
        succParent ->right = succ->right;
    
    free(succ);
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

    printf("Original BST: ");
    inorder(root);
  
    printf("\n\nDelete a Leaf Node: 20\n");
    root = deleteNode(root, 20);
    printf("Modified BST tree after deleting Leaf Node:\n");
    inorder(root);

    printf("\n\nDelete Node with single child: 70\n");
    root = deleteNode(root, 70);
    printf("Modified BST tree after deleting single child Node:\n");
    inorder(root);

    printf("\n\nDelete Node with both child: 50\n");
    root = deleteNode(root, 50);
    printf("Modified BST tree after deleting both child Node:\n");
    inorder(root);

    return 0;
}