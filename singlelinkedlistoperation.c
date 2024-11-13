#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int value) {
    Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

Node *concat(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

Node *sort(Node *head) {
    if (head == NULL) return NULL;

    Node *temp, *current;
    int t;
    current = head;
    while (current != NULL) {
        temp = head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

Node *reverse(Node *head) {
    Node *prev = NULL, *temp, *next;
    temp = head;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

void displayLinkedList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;

    list1 = insertAtBeginning(list1, 1);
    list1 = insertAtBeginning(list1, 2);
    list1 = insertAtBeginning(list1, 3);

    list2 = insertAtBeginning(list2, 4);
    list2 = insertAtBeginning(list2, 5);
    list2 = insertAtBeginning(list2, 6);

    printf("Linked List 1: ");
    displayLinkedList(list1);
    printf("Linked List 2: ");
    displayLinkedList(list2);

    printf("After Sorting:\n");
    list1 = sort(list1);
    list2 = sort(list2);
    printf("Linked List 1: ");
    displayLinkedList(list1);
    printf("Linked List 2: ");
    displayLinkedList(list2);

    printf("After concatenation:\n");
    list1 = concat(list1, list2);
    displayLinkedList(list1);

    printf("After reversing:\n");
    list1 = reverse(list1);
    displayLinkedList(list1);

    return 0;
}

