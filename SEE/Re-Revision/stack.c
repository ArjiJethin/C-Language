#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top == NULL;
    return stack;
}

int isEMpty(struct Stack *stack)
{
    return stack->top == NULL;
}

void push(struct Stack *stack, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d to stack\n", value);
}

int pop(struct Stack *stack)
{
    if (isEMpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

int main()
{
    struct Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Popped %d from stack\n", pop(stack));
    printf("Popped %d from stack\n", pop(stack));
    printf("Popped %d from stack\n", pop(stack));
    printf("Popped %d from stack\n", pop(stack));
    return 0;
}