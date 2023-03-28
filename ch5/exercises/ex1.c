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

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printTree(Node *root, int depth, int spaces) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, depth + 1, spaces + 4);

    printSpaces(spaces);
    printf("%d\n", root->data);

    printTree(root->left, depth + 1, spaces + 4);
}

int main() {
    Node *root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);

    printTree(root, 0, 0);

    return 0;
}

