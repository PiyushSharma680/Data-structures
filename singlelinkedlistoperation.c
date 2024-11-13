#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void pushStack(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Pushed to stack: %d\n", data);
}


void popStack(struct Node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Popped from stack: %d\n", temp->data);
    free(temp);
}


void enqueueQueue(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Enqueued to queue: %d\n", data);
}


void dequeueQueue(struct Node** head) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Dequeued from queue: %d\n", temp->data);
    free(temp);
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    printf("Current List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("None\n");
}

int main() {
    struct Node* linkedList = NULL;


    printf("Stack Operations:\n");
    pushStack(&linkedList, 10);
    pushStack(&linkedList, 20);
    pushStack(&linkedList, 30);
    display(linkedList);
    popStack(&linkedList);
    display(linkedList);


    linkedList = NULL;


    printf("\nQueue Operations:\n");
    enqueueQueue(&linkedList, 40);
    enqueueQueue(&linkedList, 50);
    enqueueQueue(&linkedList, 60);
    display(linkedList);
    dequeueQueue(&linkedList);
    display(linkedList);

    return 0;
}

