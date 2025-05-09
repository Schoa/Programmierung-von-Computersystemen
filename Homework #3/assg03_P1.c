#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strcpy

// Define the structure for a Customer node
typedef struct Node {
    char ID[11];       // Customer ID (max 10 characters)
    char Name[30];     // Customer Name (max 30 characters)
    int Points;        // Loyalty points for the customer

    struct Node *next; // Pointer to the next node in the linked list
} Customer;

// Function to create a new Customer node
Customer *create(const char *ID) {
    Customer *newNode = (Customer *)malloc(sizeof(Customer)); // Allocate memory for the new node
    if (!newNode) { // Check if memory allocation failed
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    strcpy(newNode->ID, ID); // Copy the provided ID into the node's ID field
    newNode->next = NULL;    // Initialize the next pointer to NULL
    return newNode;          // Return the newly created node
}

// Function to insert a Customer at the beginning of the list
void insertAtBeginning(Customer **head, const char *ID) {
    // Check if the ID already exists in the list
    Customer *current = *head;
    while (current != NULL) {
        if (strcmp(current->ID, ID) == 0) { // Compare IDs
            printf("ID '%s' already exists. Updating the existing node.\n", ID);
            return; // Exit the function if the ID already exists
        }
        current = current->next; // Move to the next node
    }

    // If the ID does not exist, create a new node and insert it
    Customer *newNode = create(ID); // Create a new Customer node
    newNode->next = *head;          // Point the new node to the current head
    *head = newNode;                // Update the head to the new node
}

// Function to search for a Customer
void searchCustomer(Customer *head, const char *ID) {
    Customer* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->ID, ID) == 0) {
            printf("Customer Found:\n");
            printf("ID: %s \nName: %s \nPoints: %d\n", temp->ID, temp->Name, temp->Points);
            return; // Exit the function after finding the customer
        }
        temp = temp->next;
    }
    printf("Customer with ID '%s' not found.\n", ID);
}

// Function to print all Customers in the list
void printCustomer(Customer* head) {
    if (head == NULL) { // Check if the list is empty
        printf("The customer list is empty.\n");
        return;
    }

    Customer* temp = head; // Start from the head of the list
    while (temp != NULL) { // Traverse the list until the end
        printf("ID: %s \nName: %s \nPoints: %d\n", temp->ID, temp->Name, temp->Points); // Print Customer details
        temp = temp->next; // Move to the next node
    }
}

// Function to delete a Customer by ID
void deleteCustomer(Customer **head, const char *value) {
    if (*head == NULL) { // Check if the list is empty
        printf("The customer list is empty. Nothing to delete.\n");
        return;
    }
    if (strcmp((*head)->ID, value) == 0) { // Check if the head node matches the ID
        Customer *temp = *head; // Store the head node in a temporary variable
        *head = (*head)->next;  // Update the head to the next node
        free(temp);             // Free the memory of the deleted node
        printf("Customer with ID '%s' deleted.\n", value);
        return;
    }
    Customer *current = *head; // Start from the head of the list
    while (current->next != NULL && strcmp(current->next->ID, value) != 0) { // Traverse the list to find the node
        current = current->next; // Move to the next node
    }
    if (current->next != NULL) { // If the node is found
        Customer *temp = current->next; // Store the node to be deleted
        current->next = current->next->next; // Update the next pointer to skip the deleted node
        free(temp); // Free the memory of the deleted node
        printf("Customer with ID '%s' deleted.\n", value);
    } else {
        printf("Customer with ID '%s' not found.\n", value);
    }
}

int main() {
    Customer* head = NULL; // Initialize the head of the list to NULL
    int n; // Variable to store the user's choice
    char ID[11]; // Variable to store the Customer ID
    char Name[30]; // Variable to store the Customer Name
    int Points; // Variable to store the Customer Points

    while (1) { // Infinite loop for the menu
        // Display the menu for the loyalty program
        printf("\n---Vinair Loyalty Program---\n");
        printf("1. Insert Customer\n");
        printf("2. Search Customer\n");
        printf("3. Delete Customer\n");
        printf("4. Display all Customers\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n); // Read the user's choice

        switch (n) {
            case 1: // Insert Customer
                printf("Enter Customer ID: ");
                scanf("%s", ID);
                getchar(); // Consume the newline character left by scanf

                printf("Enter Customer Name: ");
                fgets(Name, sizeof(Name), stdin);
                Name[strcspn(Name, "\n")] = '\0'; // Remove the trailing newline character

                printf("Enter Customer Points: ");
                scanf("%d", &Points);

                insertAtBeginning(&head, ID); // Insert the customer
                strcpy(head->Name, Name); // Update the Name field
                head->Points = Points; // Update the Points field
                printf("Customer inserted successfully.\n");
                break;

            case 2: // Search Customer
                printf("Enter Customer ID to search: ");
                scanf("%s", ID);
                searchCustomer(head, ID); // Pass the correct variable
                break;

            case 3: // Delete Customer
                printf("Enter Customer ID to delete: ");
                scanf("%s", ID);
                deleteCustomer(&head, ID); // Delete the customer
                break;

            case 4: // Display all Customers
                printf("Customer List:\n");
                printCustomer(head); // Print all customers
                break;

            case 5: // Save and Exit
                printf("Exiting the program. Goodbye!\n");
                // Free the memory allocated for the list
                while (head != NULL) {
                    Customer* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0); // Exit the program

            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }
}