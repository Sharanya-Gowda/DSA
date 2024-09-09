#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

void initialize(Stack *stack) {
    stack->capacity = INITIAL_CAPACITY;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    if (stack->arr == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void resize(Stack *stack) {
    stack->capacity *= 2;
    stack->arr = (int *)realloc(stack->arr, stack->capacity * sizeof(int));
    if (stack->arr == NULL) {
        printf("Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void push(Stack *stack, int data) {
    if (isFull(stack)) {
        resize(stack);
    }
    stack->arr[++stack->top] = data;
    printf("%d pushed to stack\n", data);
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return some error value
    }
    return stack->arr[stack->top--];
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice, data;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                printf("%d popped from stack\n", pop(&stack));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    free(stack.arr); // Free dynamically allocated memory

    return 0;
}
