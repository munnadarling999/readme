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

// Function to find the minimum value node in a BST (leftmost node)
struct Node* findMinNode(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to delete a node with given data from BST
struct Node* deleteNode(struct Node* root, int key) {
    // If the tree is empty, return NULL
    if (root == NULL)
        return NULL;

    // Search for the node to be deleted in the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // Search for the node to be deleted in the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // If the node with the given data is found
    else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct Node* temp = findMinNode(root->right); // Find the inorder successor (smallest node in the right subtree)
        root->data = temp->data; // Copy the inorder successor's data to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
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
    // Create a BST
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("Inorder traversal of the original BST: ");
    inorderTraversal(root);
    printf("\n");

    // Delete a node with value 30
    root = deleteNode(root, 30);

    printf("Inorder traversal of the BST after deleting node with value 30: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
