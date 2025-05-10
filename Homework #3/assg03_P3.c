#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a heap structure
typedef struct Heap {
    char** ID;       // Array of Order IDs
    char** Name;     // Array of Customer Names
    int* Priority;   // Array of Priorities

    int size;
    int capacity;
} Order;

// Forward Declarations
Order* createHeap(int capacity);
void insertHelper(Order* heap, int index);
void heapify(Order* heap, int index);
int extractMin(Order* heap);
void insert(Order* heap, const char* ID, const char* Name, int Priority);
void freeHeap(Order* heap);

// Define a createHeap function
Order* createHeap(int capacity) {
    // Allocate memory for the heap
    Order* heap = (Order*)malloc(sizeof(Order));
    if (heap == NULL) {
        printf("Error: Memory allocation error\n");
        exit(1);
    }

    // Set the values for size and capacity
    heap->size = 0;
    heap->capacity = capacity;

    // Allocate memory for Priority, ID, and Name arrays
    heap->Priority = (int*)malloc(capacity * sizeof(int));
    heap->ID = (char**)malloc(capacity * sizeof(char*));
    heap->Name = (char**)malloc(capacity * sizeof(char*));

    for (int i = 0; i < capacity; i++) {
        heap->ID[i] = (char*)malloc(20 * sizeof(char));  // Allocate memory for each ID
        heap->Name[i] = (char*)malloc(30 * sizeof(char)); // Allocate memory for each Name
    }

    if (heap->Priority == NULL || heap->ID == NULL || heap->Name == NULL) {
        printf("Error: Memory allocation error\n");
        exit(1);
    }

    return heap;
}

// Free the heap memory
void freeHeap(Order* heap) {
    for (int i = 0; i < heap->capacity; i++) {
        free(heap->ID[i]);
        free(heap->Name[i]);
    }
    free(heap->ID);
    free(heap->Name);
    free(heap->Priority);
    free(heap);
}

// Define insertHelper function
void insertHelper(Order* heap, int index) {
    int parent = (index - 1) / 2;

    if (heap->Priority[parent] > heap->Priority[index]) {
        // Swap Priority
        int tempPriority = heap->Priority[parent];
        heap->Priority[parent] = heap->Priority[index];
        heap->Priority[index] = tempPriority;

        // Swap ID
        char tempID[20];
        strcpy(tempID, heap->ID[parent]);
        strcpy(heap->ID[parent], heap->ID[index]);
        strcpy(heap->ID[index], tempID);

        // Swap Name
        char tempName[30];
        strcpy(tempName, heap->Name[parent]);
        strcpy(heap->Name[parent], heap->Name[index]);
        strcpy(heap->Name[index], tempName);

        // Recursively call insertHelper
        insertHelper(heap, parent);
    }
}

// Define heapify function
void heapify(Order* heap, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = index;

    if (left < heap->size && heap->Priority[left] < heap->Priority[min]) {
        min = left;
    }
    if (right < heap->size && heap->Priority[right] < heap->Priority[min]) {
        min = right;
    }

    if (min != index) {
        // Swap Priority
        int tempPriority = heap->Priority[min];
        heap->Priority[min] = heap->Priority[index];
        heap->Priority[index] = tempPriority;

        // Swap ID
        char tempID[20];
        strcpy(tempID, heap->ID[min]);
        strcpy(heap->ID[min], heap->ID[index]);
        strcpy(heap->ID[index], tempID);

        // Swap Name
        char tempName[30];
        strcpy(tempName, heap->Name[min]);
        strcpy(heap->Name[min], heap->Name[index]);
        strcpy(heap->Name[index], tempName);

        // Recursively call heapify
        heapify(heap, min);
    }
}

// Define extractMin function
int extractMin(Order* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -999;
    }

    int minPriority = heap->Priority[0];

    // Replace the root with the last element
    strcpy(heap->ID[0], heap->ID[heap->size - 1]);
    strcpy(heap->Name[0], heap->Name[heap->size - 1]);
    heap->Priority[0] = heap->Priority[heap->size - 1];

    heap->size--;

    // Re-heapify to maintain heap property
    heapify(heap, 0);

    return minPriority;
}

// Define insert function
void insert(Order* heap, const char* ID, const char* Name, int Priority) {
    if (heap->size < heap->capacity) {
        // Insert Priority
        heap->Priority[heap->size] = Priority;

        // Insert ID and Name
        strcpy(heap->ID[heap->size], ID);
        strcpy(heap->Name[heap->size], Name);

        // Maintain heap property
        insertHelper(heap, heap->size);

        // Increment size
        heap->size++;
    } else {
        printf("Heap is full. Cannot insert new order.\n");
    }
}

// Function to print the heap
void printHeap(Order* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("\n---Heap Contents---\n");
    for (int i = 0; i < heap->size; i++) {
        printf("Order ID: %s, Customer Name: %s, Priority: %d\n", heap->ID[i], heap->Name[i], heap->Priority[i]);
    }
}

// Function to update the priority of an order
void updatePriority(Order* heap, const char* ID, int newPriority) {
    int found = 0;
    for (int i = 0; i < heap->size; i++) {
        if (strcmp(heap->ID[i], ID) == 0) {
            printf("Updating priority for Order ID: %s\n", ID);
            heap->Priority[i] = newPriority;

            // Re-heapify to maintain heap property
            heapify(heap, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Order with ID '%s' not found.\n", ID);
    }
}

int main() {
    Order* heap = createHeap(10);

    int n;
    char ID[20];
    char Name[30];
    int Priority;

    while (1) {
        printf("\n---Vinfood Order System---\n");
        printf("1. Insert New Order\n");
        printf("2. Display Heap\n");
        printf("3. Process Next Order\n");
        printf("4. Update Priority\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter Order ID: ");
                scanf("%s", ID);
                printf("Enter Customer Name: ");
                getchar(); // Consume leftover newline
                fgets(Name, sizeof(Name), stdin);
                Name[strcspn(Name, "\n")] = '\0'; // Remove trailing newline
                printf("Enter Priority (1-10): ");
                scanf("%d", &Priority);
                insert(heap, ID, Name, Priority);
                printf("Order inserted successfully.\n");
                break;

            case 2:
                printHeap(heap);
                break;

            case 3:
                if (heap->size == 0) {
                    printf("No orders to process.\n");
                } else {
                    int nextOrder = extractMin(heap);
                    printf("Processing Order with Priority: %d\n", nextOrder);
                }
                break;

            case 4:
                printf("Enter Order ID to update: ");
                scanf("%s", ID);
                printf("Enter new Priority: ");
                scanf("%d", &Priority);
                updatePriority(heap, ID, Priority);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                freeHeap(heap);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}