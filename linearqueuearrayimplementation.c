#include <stdio.h>
#include <stdlib.h> 
#define MAX 100

int queue_array[MAX];
int rear = -1;
int front = -1;

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf(" The elements of the Queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]); 
        }
        printf("\n"); 
    }
}

void insert() {
    int add_item;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) { 
            front = 0;
        }
        printf("Insert the element in Queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    } else {
        printf("Deleted Element is: %d\n", queue_array[front]);
        front = front + 1; 
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3: 
                display();
                break;
            case 4: 
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    }
}
