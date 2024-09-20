#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If list is empty, make newNode the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Make newNode the new head
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty, make newNode the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Insert the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}    

// Function to insert a node at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    
    // If inserting at the head (position 1)
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    // Traverse to the node just before the position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // If the position is beyond the list length
    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return;
    }
    
    // Inserting in the middle or end
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the linked list
void displayList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data, position, f, g;
    
    printf("Enter the number of elements to insert at beginning: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    }
    printf("Enter the number of elements to insert at end: ");
    scanf("%d", &f);
    
    for (int i = 0; i < f; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("Enter the number of elements to insert at any position: ");
    scanf("%d", &g);
    
    for (int i = 0; i < g; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        printf("Enter the position to insert the node: ");
        scanf("%d", &position);
        insertAtPosition(&head, data, position);
        displayList(head);  // Display list after every insertion
    }
    
    displayList(head);
    
    return 0;
}