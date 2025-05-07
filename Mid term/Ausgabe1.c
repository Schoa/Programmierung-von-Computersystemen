#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *createLinkedList( int data) {
    node *newNode = (node*)malloc(sizeof(node));
    if(!newNode) {
        printf("ERROR \n");
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
