#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a data onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a data from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped element:%d",data);
    printf("\n");
}

// Function to display the stack
void displayStack(struct Stack* stack) {
    struct Node* temp = stack->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Initializing stack
    struct Stack stack = {NULL};

    int choice, data,n;

    do {
        printf("\n Stacks Operations:");
        printf("1. Push\t2. Pop\t3. Display\t0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter no of elements:");
                scanf("%d",&n);
                printf("Enter %d the elements to insert: ",n);
                for(int i=0;i<n;i++){
                    scanf("%d", &data);
                    push(&stack, data);
                }
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                displayStack(&stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}