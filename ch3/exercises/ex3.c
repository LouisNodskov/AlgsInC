#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void exchange(struct node *t, struct node *u) {
    // Check if t and u are the same node or if either is NULL
    if (t == NULL || u == NULL || t == u) {
        return;
    }

    // Check if t and u are consecutive nodes
    if (t->next == u) {
        t->next = u->next;
        u->next = t;
    } else if (u->next == t) {
        u->next = t->next;
        t->next = u;
    } else {
        struct node* temp = t->next;
        t->next = u->next;
        u->next = temp;
        temp = t->next->next;
        t->next->next = u->next->next;
        u->next->next = temp;
    }
}

int main() {
    // Create a linked list with five nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 3;
    head->next->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    // Print the original list
    printf("Original list: %d -> %d -> %d -> %d -> %d\n",
           head->data, head->next->data, head->next->next->data,
           head->next->next->next->data, head->next->next->next->next->data);

    // Exchange the nodes after the second and fourth nodes
    exchange(head->next, head->next->next->next);

    // Print the modified list
    printf("Modified list: %d -> %d -> %d -> %d -> %d\n",
           head->data, head->next->data, head->next->next->data,
           head->next->next->next->data, head->next->next->next->next->data);

    // Free the memory used by the list
    free(head->next->next->next->next);
    free(head->next->next->next);
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
