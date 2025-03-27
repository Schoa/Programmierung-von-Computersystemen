#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function Prototype
void list_add(Node **head, int value);
void list_print(Node *head);
void list_delete(Node **head, int value);
Node* list_research(Node *head, int value);

int main() {
    Node *head = NULL;

    list_add(&head, 5);
    list_add(&head, 15);
    list_add(&head, 10);
    list_print(head); // Output: 10 15 5

    list_delete(&head, 15);
    list_print(head); // Output: 10 5

    Node *found_node = list_research(head, 10);
    if (found_node != NULL) {
        printf("Found value: %d\n", found_node -> data);
    } else {
        printf("Value not found\n");
    }

    return 0;
}

void list_add(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void list_print(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void list_delete(Node **head, int value) {
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

Node* list_research(Node *head, int value) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}