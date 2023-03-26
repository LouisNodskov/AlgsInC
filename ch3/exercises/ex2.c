#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void movenexttofront(struct node **head, struct node *t) {
    struct node *temp = t->next;

    // If there is no node after t, do nothing
    if (temp == NULL) {
        return;
    }

    // Detach the node after t from the list
    t->next = temp->next;

    // Move the detached node to the front of the list
    temp->next = *head;
    *head = temp;
}

int main() {
    struct node *head = NULL;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 5; i > 0; i--) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    // Print the original list
    printf("Original list: ");
    struct node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // Move the node following the second node to the front of the list
    movenexttofront(&head, head->next);

    // Print the modified list
    printf("Modified list: ");
    p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    free(head);

    return 0;
}
