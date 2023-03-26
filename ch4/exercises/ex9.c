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

// Define a function to perform postorder traversal of a binary tree using a stack
void postOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    // Create two stacks for postorder traversal
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    // Push the root node onto stack 1
    stack1[++top1] = root;

    // Pop nodes from stack 1 and push them onto stack 2 in the right-to-left order
    while (top1 >= 0) {
        struct Node *node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }

        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }

    // Pop nodes from stack 2 and print their data
    while (top2 >= 0) {
        struct Node *node = stack2[top2--];
        printf("%d ", node->data);
    }
}

// Define the main function to test the postorder traversal function
int main() {
    // Create a binary tree with three nodes
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    // Create a binary tree with two nodes
    struct Node *root2 = newNode(4);
    root2->left = newNode(5);

    // Make the root of the first binary tree point to the root of the second binary tree
    root->left->left = root2;

    // Test the postorder traversal function on the binary tree
    printf("Postorder traversal of the binary tree: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}

