#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 100; // Set an arbitrary capacity
    obj->stack1 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->stack2 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top1 = 0;
    obj->top2 = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[obj->top1++] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 > 0) {
            obj->stack2[obj->top2++] = obj->stack1[--obj->top1];
        }
    }
    return obj->stack2[--obj->top2];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 > 0) {
            obj->stack2[obj->top2++] = obj->stack1[--obj->top1];
        }
    }
    return obj->stack2[obj->top2 - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == 0 && obj->top2 == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

int main() {
    MyQueue* queue = myQueueCreate();
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    printf("%d\n", myQueuePeek(queue)); 
    printf("%d\n", myQueuePop(queue));  
    printf("%d\n", myQueueEmpty(queue)); 
    myQueueFree(queue);
    return 0;
}
