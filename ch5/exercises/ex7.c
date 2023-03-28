#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void postorder(struct node *root) {
    if (root == NULL)
        return;

    struct node *stack[100];
    int top = -1;

    do {
        while (root) {
            if (root->right)
                stack[++top] = root->right;
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];

        if (root->right && stack[top] == root->right) {
            top--;
            stack[++top] = root;
            root = root->right;
        } else {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (top >= 0);
}

int main() {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 2;
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

