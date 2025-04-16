#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the height of the tree
int findHeight(struct Node* root) {
    if (root == NULL)
        return -1;  // height of empty tree is -1
    else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        // Return the larger one plus 1
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int height = findHeight(root);
    printf("Height of the tree: %d\n", height);

    return 0;
}
