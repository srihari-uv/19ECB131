#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for level order construction
struct Queue {
    int front, rear, size;
    struct Node** array;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Create a queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = size;
    q->array = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, struct Node* node) {
    q->array[q->rear++] = node;
}

// Dequeue operation
struct Node* dequeue(struct Queue* q) {
    return q->array[q->front++];
}

// Check if queue is empty
int isQueueEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from user input
struct Node* buildTree(int n) {
    if (n <= 0) return NULL;

    int val;
    printf("Enter value for root: ");
    scanf("%d", &val);

    struct Node* root = createNode(val);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int count = 1;

    while (count < n) {
        struct Node* current = dequeue(q);

        // Left child
        printf("Enter left child of %d (or -1 for NULL): ", current->data);
        scanf("%d", &val);
        if (val != -1) {
            current->left = createNode(val);
            enqueue(q, current->left);
            count++;
        }

        if (count >= n) break;

        // Right child
        printf("Enter right child of %d (or -1 for NULL): ", current->data);
        scanf("%d", &val);
        if (val != -1) {
            current->right = createNode(val);
            enqueue(q, current->right);
            count++;
        }
    }

    return root;
}

// Inorder traversal for testing
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* root = buildTree(n);

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
