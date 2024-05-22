#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node*left;
	struct Node*right;
	int height;
};
int height(struct Node* node) {
	if (node == NULL)
	return 0;
	return node->height;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

struct Node* newNode(int key){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

struct Node* rightRotate(struct Node* y) {
	struct Node* x = y->left;
	struct Node* T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(y->left), height(x->right)) + 1;
	
	return x;
}

struct Node* leftRotate(struct Node* x) {
	struct Node* y = x->right;
	struct Node* T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	return y;
}

int getBalance(struct Node* node) {
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int key) {
	if (node == NULL)
	return newNode(key);
	
	if (key < node->key)
	    node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
	return node;
	
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balance = getBalance(node);
	
	if (balance > 1 && key < node->left->key)
	return rightRotate(node);
	
	if (balance < -1 && key > node->right->key)
    return leftRotate(node);
    
    if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);		
}
    if (balance < -1 && key < node->right->key) {
    	node->right = rightRotate(node->right);
    	return rightRotate(node);
    }
    
    return node;
}

struct Node* deleteNode(struct Node* root, int key) {
	return root;
}
void preOrderTraversal(struct Node* root ) {
	if (root != NULL) {
		printf("%d ", root->key);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void displayMenu() {
	printf("\nAVL Tree Menu\n");
	printf("1. Insert Node\n");
	printf("2. Delete Node\n");
	printf("3. Traverse Balanced Tree (Pre-order)\n");
	printf("4. Exit\n");
}

int main(){
	struct Node* root = NULL;
	int choice, key;
	
	do{
		displayMenu();
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("Enter key to insert: ");
				scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
            	printf("Enter key to delete: ");
            	scanf("%d", &key);
                root = deleteNode(root, key);
            	break;
            case 3:
            	printf("Pre-order Traversal: ");
            	preOrderTraversal(root);
            	printf("\n");
            	break;
            case 4:
            	printf("Exiting program.\n");
            	break;
            default:
            	printf("Invalid choice. Please try again.\n");
    
		}
	} while (choice != 4);
	
	return 0;
}