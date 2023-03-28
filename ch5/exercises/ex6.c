#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct StackNode {
    Node *data;
    struct StackNode *next;
} StackNode;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

StackNode* newStackNode(Node *data) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

void push(StackNode **stack, Node *data) {
    StackNode *newNode = newStackNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

Node* pop(StackNode **stack) {
    if (*stack == NULL) {
        return NULL;
    }

    StackNode *topNode = *stack;
    *stack = topNode->next;
    Node *data = topNode->data;
    free(topNode);
    return data;
}

bool isEmpty(StackNode *stack) {
    return stack == NULL;
}

void inorderTraversal(Node *root) {
    StackNode *stack = NULL;
    Node *current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

int main() {
    Node *root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);

    printf("Inorder Traversal:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
