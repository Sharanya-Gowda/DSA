#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isFull(Queue *queue) {
    return (queue->rear ==MAX_SIZE -1);
}

bool isEmpty(Queue *queue) {
    return queue->front == -1 && queue->rear == -1;
}

void enqueue(Queue *queue, int data) {
    if(isFull(queue)){
        printf("Queue is full");
    }
    queue->arr[++queue->rear] = data;
    printf("%d is added\n",data);
}

int dequeue(Queue *queue) {
    int data;
    if(isEmpty(queue)){
        printf("Queue is full");
    }
    data=queue->arr[++queue->front];
    printf("%d is removed\n",data);
}

int main() {
    Queue queue;
    initialize(&queue);

    int choice, data;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
