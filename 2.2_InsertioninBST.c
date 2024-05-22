#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into an existing BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node and return it as root
    if (root == NULL)
        return createNode(data);

    // Otherwise, traverse the tree to find the appropriate position to insert the new node
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to perform inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    // Existing Binary Search Tree
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    // Print the inorder traversal of the existing BST
    printf("Inorder traversal of the existing BST: ");
    inorderTraversal(root);
    printf("\n");

    // Insert a new node with value 35 into the existing BST
    int newData = 35;
    root = insert(root, newData);

    // Print the inorder traversal of the BST after insertion
    printf("Inorder traversal of the BST after insertion of %d: ", newData);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
