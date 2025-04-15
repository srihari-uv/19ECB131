#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//to allocate memory dynamically
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // If data is less than the root's data, insert into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is greater than the root's data, insert into the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-order traversal of the binary search tree (prints values in ascending order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the binary search tree in in-order
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

Output:

In-order traversal of the BST: 20 30 40 50 60 70 80
