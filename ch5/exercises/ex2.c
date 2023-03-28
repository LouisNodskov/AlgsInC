#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int externalPathLength(Node *root, int depth) {
    if (root == NULL) {
        return depth;
    }

    int leftPathLength = externalPathLength(root->left, depth + 1);
    int rightPathLength = externalPathLength(root->right, depth + 1);

    return leftPathLength + rightPathLength;
}

int main() {
    Node *root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);

    int pathLength = externalPathLength(root, 0);
    printf("External Path Length: %d\n", pathLength);
}
