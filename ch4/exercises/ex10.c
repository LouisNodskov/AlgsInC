#include <stdio.h>
#include <stdlib.h>

// Define a struct for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Define a function to create a new binary tree node with a given value
struct Node *newNode(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to perform level-order traversal of a binary tree
void levelOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    // Create an empty queue for level-order traversal
    struct Node *queue[100];
    int front = 0, rear = 0;

    // Enqueue the root node and mark it as visited
    queue[rear++] = root;

    while (front != rear) {
        // Dequeue a node from the queue and print its data
        struct Node *node = queue[front++];
        printf("%d ", node->data);

        // Enqueue the left child if it exists and mark it as visited
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }

        // Enqueue the right child if it exists and mark it as visited
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

// Define the main function to test the level-order traversal function
int main() {
    // Create a binary tree with three nodes
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    // Create a binary tree with two nodes
    struct Node *root2 = newNode(4);
    root2->left = newNode(5);

    // Create a binary tree with four nodes
    struct Node *root3 = newNode(6);
    root3->left = newNode(7);
    root3->right = newNode(8);
    root3->right->left = newNode(9);

    // Make the root of the first binary tree point to the root of the second binary tree
    root->left->left = root2;

    // Make the root of the second binary tree point to the root of the third binary tree
    root2->right = root3;

    // Test the level-order traversal function on the forest represented by the binary tree
    printf("Level-order traversal of the forest:\n");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}

