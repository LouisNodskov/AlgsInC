#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct node **headRef, int data) {
    struct node *newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
        *headRef = newNode;
    }
}

void insertAtEnd(struct node **headRef, int data) {
    struct node *newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct node *temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNode(struct node **headRef, struct node *delNode) {
    if (*headRef == NULL || delNode == NULL) {
        return;
    }
    if (*headRef == delNode) {
        *headRef = delNode->next;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    free(delNode);
}

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printList(head);
    deleteNode(&head, head);
    printList(head);
    deleteNode(&head, head->next->next);
    printList(head);
    return 0;
}
