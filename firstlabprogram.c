#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int element) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = element;
        printf("%d pushed onto stack\n", element);
    }
}
int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int poppedElement = stack[top--];
        printf("%d popped from stack\n", poppedElement);
        return poppedElement;
    }
}
void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
int main() {
    int choice, element;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
