#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a threaded binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int lthread; // Flag to check if left pointer is a thread (1 = thread, 0 = child)
    int rthread; // Flag to check if right pointer is a thread (1 = thread, 0 = child)
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->lthread = 0;
    node->rthread = 0;
    return node;
}

// Function to insert a new node in the threaded binary tree
void insert(struct Node** root, int data) {
    struct Node* new_node = newNode(data);
    if (*root == NULL) {
        *root = new_node;
        return;
    }

    struct Node* temp = *root;
    struct Node* parent = NULL;

    // Traverse to the correct location to insert the node
    while (temp != NULL) {
        parent = temp;
        if (data < temp->data) {
            if (temp->lthread == 0) {
                temp = temp->left;
            } else {
                break;
            }
        } else {
            if (temp->rthread == 0) {
                temp = temp->right;
            } else {
                break;
            }
        }
    }

    // Inserting the node in the correct location
    if (data < parent->data) {
        parent->left = new_node;
        parent->lthread = 0;
        new_node->left = NULL;
        new_node->right = parent;
        new_node->rthread = 1;
    } else {
        parent->right = new_node;
        parent->rthread = 0;
        new_node->left = parent;
        new_node->lthread = 1;
    }
}

// In-order traversal of the threaded binary tree
void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    // Find the leftmost node
    struct Node* temp = root;
    while (temp->lthread == 0)
        temp = temp->left;

    // Traverse the tree using threads
    while (temp != NULL) {
        printf("%d ", temp->data);
        
        // If the right pointer is a thread, move to the next node
        if (temp->rthread == 1) {
            temp = temp->right;
        } else {
            // Otherwise, move to the leftmost node of the right subtree
            temp = temp->right;
            while (temp != NULL && temp->lthread == 0)
                temp = temp->left;
        }
    }
}

// Main function to demonstrate the threaded binary tree
int main() {
    struct Node* root = NULL;

    // Inserting nodes into the threaded binary tree
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 2);
    insert(&root, 8);

    // Performing in-order traversal
    printf("In-order Traversal of Threaded Binary Tree:\n");
    inOrderTraversal(root);

    return 0;
}

OUTPUT:

In-order Traversal of Threaded Binary Tree:
Segmentation fault
