#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heapSize && heap[leftChild] > heap[largest])
        largest = leftChild;

    if (rightChild < heapSize && heap[rightChild] > heap[largest])
        largest = rightChild;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        maxHeapify(largest);
    }
}

void insert(int item) {
    if (heapSize >= MAX_SIZE) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    heap[heapSize] = item;
    int current = heapSize;
    while (current > 0 && heap[current] > heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }

    heapSize++;
}

void deleteMax() {
    if (heapSize <= 0) {
        printf("Heap is empty. Cannot delete.\n");
        return -1; // Indicate failure
    }

    int deletedItem = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    maxHeapify(0); 

    printf("\nDeleted element:%d",deletedItem);
}

void display() {
    if (heapSize <= 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Max Heap: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

  int main() {
    int choice, n, item;
    
    do {
        printf("\n1. Insert\t2. Delete Max\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements to insert: ");
                scanf("%d", &n);

                printf("Enter %d elements to insert into the max heap:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &item);
                    insert(item);
                }
                break;

            case 2:
                deleteMax();
                printf("\n");
                display();
                break;

            case 3:
                display();
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
