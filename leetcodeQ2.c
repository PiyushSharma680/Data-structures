#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *data;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char *)malloc(sizeof(char) * capacity);
    return stack;
}

bool isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char c)
{
    if (!isFull(stack))
    {
        stack->data[++stack->top] = c;
    }
}

char pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    return '\0';
}

char peek(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top];
    }
    return '\0';
}

void freeStack(Stack *stack)
{
    free(stack->data);
    free(stack);
}

bool isValid(char *s)
{
    Stack *stack = createStack(100);

    for (int i = 0; s[i] != '\0'; i++)
    {
        char current = s[i];

        if (current == '(' || current == '{' || current == '[')
        {
            push(stack, current);
        }
        else
        {

            if (isEmpty(stack))
            {
                freeStack(stack);
                return false;
            }
            char top = pop(stack);
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '['))
            {
                freeStack(stack);
                return false;
            }
        }
    }

    bool result = isEmpty(stack);
    freeStack(stack);
    return result;
}

int main()
{
    char *input = (char *)malloc(sizeof(char) * 10000);
    printf("Enter a string of parentheses: ");
    scanf("%s", input);
    if (isValid(input))
    {
        printf("The input string is valid.\n");
    }
    else
    {
        printf("The input string is not valid.\n");
    }

    free(input);
    return 0;
}
