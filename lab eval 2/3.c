#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int isEmpty() {
    return top == -1;
}

void insertAtBottom(int x) {
    if (isEmpty()) {
        push(x);
    } else {
        int temp = pop();
        insertAtBottom(x);
        push(temp);
    }
}

void reverseStack() {
    if (!isEmpty()) {
        int temp = pop();
        reverseStack();
        insertAtBottom(temp);
    }
}

void display() {
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    printf("Original Stack:\n");
    display();
    reverseStack();
    printf("Reversed Stack:\n");
    display();
    return 0;
}
