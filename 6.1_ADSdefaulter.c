#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int areEqualBSTs(struct TreeNode* root1, struct TreeNode* root2) {
    struct TreeNode* stack1[100];
    struct TreeNode* stack2[100];
    int top1 = -1, top2 = -1;

    while (1) {
        while (root1 != NULL) {
            stack1[++top1] = root1;
            root1 = root1->left;
        }
        while (root2 != NULL) {
            stack2[++top2] = root2;
            root2 = root2->left;
        }

        if (top1 == -1 && top2 == -1)
            break;
        if ((top1 == -1) != (top2 == -1))
            return 0;

        root1 = stack1[top1--];
        root2 = stack2[top2--];

        if (root1->val != root2->val)
            return 0;

        root1 = root1->right;
        root2 = root2->right;
    }

    return 1;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    struct TreeNode* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(15);
    root1->left->left = newNode(3);
    root1->left->right = newNode(9);
    root1->right->left = newNode(12);
    root1->right->right = newNode(18);

    struct TreeNode* root2 = newNode(10);
    root2->left = newNode(5);
    root2->right = newNode(15);
    root2->left->left = newNode(3);
    root2->left->right = newNode(7);
    root2->right->left = newNode(12);
    root2->right->right = newNode(18);

    if (areEqualBSTs(root1, root2))
        printf("BSTs are equivalent.\n");
    else
        printf("BSTs are not equivalent.\n");

    return 0;
}
