#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* createBST() {
    int x;
    struct Node* newNode;
    printf("\nEnter the data (-1 for no node) : ");
    scanf("%d", &x);
    if (x == -1) {
        return NULL;
    }
    newNode = createNode(x);
    printf("\nEnter the left child of %d : ", x);
    newNode->left = createBST();
    printf("\nEnter the right child of %d : ", x);
    newNode->right = createBST();
    return newNode;
}

void printpreorder(struct Node* root) {
    if (root!= NULL) {
        printpreorder(root->left);
        printf("%d ", root->data);
        printpreorder(root->right);
    }
}
void printInorder(struct Node* root) {
    if (root!= NULL) {
        printf("%d ", root->data);
        printInorder(root->left);
        printInorder(root->right);
    }
}
void printpostorder(struct Node* root) {
    if (root!= NULL) {
        printpostorder(root->left);
        printpostorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct Node* root = createBST();
    printf("\nThe preorder traversal of the BST is: ");
    printpreorder(root);
    printf("\nThe inorder traversal of the BST is: ");
    printInorder(root);
    printf("\nThe postorder traversal of the BST is: ");
    printpostorder(root);
    return 0;
}