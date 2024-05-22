#include <stdio.h>
#include <stdlib.h>

struct Node 
{ 
    struct Node *left, *right; 
    int info; 
    // False if left pointer points to predecessor 
    // in Inorder Traversal 
    int lthread; 
    // False if right pointer points to successor 
    // in Inorder Traversal 
    int rthread; 
};

// Insert a Node in Binary Threaded Tree 
struct Node *insert(struct Node *root, int ikey) 
{ 
    struct Node *ptr = root; 
    struct Node *par = NULL; // Parent of key to be inserted 
    while (ptr != NULL) 
    { 
        // If key already exists, return 
        if (ikey == (ptr->info)) 
        { 
            printf("Duplicate Key !\n"); 
            return root; 
        } 
        par = ptr; // Update parent pointer 
        // Moving on left subtree. 
        if (ikey < ptr->info) 
        { 
            if (ptr->lthread == 0) 
                ptr = ptr->left; 
            else
                break; 
        } 
        // Moving on right subtree. 
        else
        { 
            if (ptr->rthread == 0) 
                ptr = ptr->right; 
            else
                break; 
        } 
    } 
    // Create a new node 
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node)); 
    tmp->info = ikey; 
    tmp->lthread = 1; 
    tmp->rthread = 1; 
    if (par == NULL) 
    { 
        root = tmp; 
        tmp->left = NULL; 
        tmp->right = NULL; 
    } 
    else if (ikey < (par->info)) 
    { 
        tmp->left = par->left; 
        tmp->right = par; 
        par->lthread = 0; 
        par->left = tmp; 
    } 
    else
    { 
        tmp->left = par; 
        tmp->right = par->right; 
        par->rthread = 0; 
        par->right = tmp; 
    } 
    return root; 
} 

// Returns inorder successor using rthread 
struct Node *inorderSuccessor(struct Node *ptr) 
{ 
    // If rthread is set, we can quickly find 
    if (ptr->rthread == 1) 
        return ptr->right; 
    // Else return leftmost child of right subtree 
    ptr = ptr->right; 
    while (ptr->lthread == 0) 
        ptr = ptr->left; 
    return ptr; 
} 

// Printing the threaded tree 
void inorder(struct Node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
    // Reach leftmost node 
    struct Node *ptr = root; 
    while (ptr->lthread == 0) 
        ptr = ptr->left; 
    // One by one print successors 
    while (ptr != NULL) 
    { 
        printf("%d ", ptr->info); 
        ptr = inorderSuccessor(ptr); 
    } 
} 

// Driver Program 
int main() 
{ 
    struct Node *root = NULL; 
    root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 30); 
    root = insert(root, 5); 
    root = insert(root, 16); 
    root = insert(root, 14); 
    root = insert(root, 17); 
    root = insert(root, 13); 
    inorder(root); 
    return 0; 
}
