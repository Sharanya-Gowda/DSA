#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0'; // Return some error value
    }
    return stack->arr[stack->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

void infixToPrefix(char *infix, char *prefix) {
    Stack operatorStack;
    initialize(&operatorStack);

    Stack resultStack;
    initialize(&resultStack);

    int len = strlen(infix);
    strrev(infix);

    for (int i = 0; i < len; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (ch == ' ') {
            continue;
        } else if (isdigit(ch) || isalpha(ch)) {
            push(&resultStack, ch);
        } else if (ch == '(') {
            push(&operatorStack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.arr[operatorStack.top] != '(') {
                push(&resultStack, pop(&operatorStack));
            }
            pop(&operatorStack); // Discard '(' from stack
        } else if (isOperator(ch)) {
            while (!isEmpty(&operatorStack) && precedence(ch) <= precedence(operatorStack.arr[operatorStack.top])) {
                push(&resultStack, pop(&operatorStack));
            }
            push(&operatorStack, ch);
        }
    }

    while (!isEmpty(&operatorStack)) {
        push(&resultStack, pop(&operatorStack));
    }

    int i = 0;
    while (!isEmpty(&resultStack)) {
        prefix[i++] = pop(&resultStack);
    }
    prefix[i] = '\0';
}

int evaluatePrefix(char *prefix) {
    Stack operandStack;
    initialize(&operandStack);

    int len = strlen(prefix);
    strrev(prefix);

    for (int i = 0; i < len; i++) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            push(&operandStack, ch - '0');
        } else if (isOperator(ch)) {
            int operand1 = pop(&operandStack);
            int operand2 = pop(&operandStack);
            switch (ch) {
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '/':
                    push(&operandStack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&operandStack);
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
