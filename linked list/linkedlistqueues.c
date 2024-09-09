#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue { 
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode =malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
        struct Node* temp = queue->front;
        int data = temp->data;
        
        if (queue->front == queue->rear) {
            queue->front = NULL;
            queue->rear = NULL;
        } else {
            queue->front = queue->front->next;
        }

        free(temp);
        printf("%d dequeued from the queue.\n", data);
    }


void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = queue->front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue={NULL};
    initializeQueue(&queue);

    int choice, data,n;

    do {
        printf("\nLinked Queue Operations:\n");
        printf("1. Enqueue\t2. Dequeue\t3. Display\t0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter no of elements:");
                scanf("%d",&n);
                printf("Enter %d the elements to insert: ",n);
                for(int i=0;i<n;i++){
                    scanf("%d", &data);
                    enqueue(&queue, data);
                }
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
