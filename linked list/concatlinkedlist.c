#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to concatenate two linked lists
void concatenateLinkedLists(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }

    struct Node* temp = *list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = list2;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertFront(&list1, 3);
    insertFront(&list1, 2);
    insertFront(&list1, 1);

    insertFront(&list2, 6);
    insertFront(&list2, 5);
    insertFront(&list2, 4);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    concatenateLinkedLists(&list1, list2);

    printf("Concatenated List: ");
    display(list1);

    return 0;
}
