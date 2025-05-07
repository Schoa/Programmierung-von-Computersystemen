/*
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node by value
struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Linked list after inserting at the end:\n");
    printList(head);

    head = insertAtBeginning(head, 5);
    printf("Linked list after inserting at the beginning:\n");
    printList(head);

    head = deleteNode(head, 20);
    printf("Linked list after deleting 20:\n");
    printList(head);

    return 0;
}
*/

#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

node *createLinkedList(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        printf("ERROR: Memmory allocation failed \n");
        exit(1);
    }
    
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void insertAtBeginning(node **head, int data)
{
    node *newNode = createLinkedList(data);
    newNode -> next = *head;
    *head = newNode;
}

void printList(node* head)
{
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL \n");
}

void deleteNode(node **head, int value) {
    if(*head == NULL){
        return;
    }
    if((*head) -> data == value){
        node *temp = *head;
        *head = (*head) -> next;
        free(temp);
        return;
    }
    node *current = *head;
    while(current -> next != NULL && current -> next -> data != value) {
        current = current-> next;
    }
    if(current -> next != NULL) {
        node *temp = current -> next;
        current -> next = current -> next -> next;
        free(temp);
    }
}

int main()
{
    struct Node* head = NULL;
    
    // Insert elements at the beginning of the list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 50);

    // Print the linked list
    printList(head); // Output: 50 20 30 10
    deleteNode(&head, 20);
    printList(head);
}
