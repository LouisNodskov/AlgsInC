#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

int value[MAX_STACK_SIZE];
int next[MAX_STACK_SIZE];
int top = -1;
int freeList = 0;

void initializeStack() {
    int i;
    for (i = 0; i < MAX_STACK_SIZE - 1; i++) {
        next[i] = i + 1;
    }
    next[MAX_STACK_SIZE - 1] = -1;
}

void push(int data) {
    if (top == -1) {
        top = freeList;
        freeList = next[freeList];
        value[top] = data;
        next[top] = -1;
    } else if (freeList != -1) {
        int newTop = freeList;
        freeList = next[freeList];
        value[newTop] = data;
        next[newTop] = top;
        top = newTop;
    } else {
        printf("Stack overflow.\n");
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow.\n");
        return -1;
    } else {
        int data = value[top];
        int temp = top;
        top = next[top];
        next[temp] = freeList;
        freeList = temp;
        return data;
    }
}

void printStack() {
    int i;
    printf("Stack contents:\n");
    for (i = top; i != -1; i = next[i]) {
        printf("%d ", value[i]);
    }
    printf("\n");
}

int main() {
    initializeStack();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printStack();
    pop();
    pop();
    printStack();
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    printStack();
    push(11);
    return 0;
}

