#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    newNode->prev = NULL; 
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode; 
}

int pop(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot pop.\n");
        return -1;
    }
    struct Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);

    printf("Popped element: %d",data);
}

void display(struct Node* head) {
    struct Node* temp =head;
    printf("Doubly Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data,n;

    do {
        printf("\n1. Push\t2. Pop\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter no of elements:");
                scanf("%d",&n);
                printf("Enter %d the elements to push: ",n);
                for(int i=0;i<n;i++){
                    scanf("%d", &data);
                    push(&head, data);
                }
                break;

            case 2:
                pop(&head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}