#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the node in the BST
typedef struct Node {
    char ID[20]; // Admission ID
    char Name[30]; // Patient Name
    int Level; // Critical Level (1-10)

    struct Node* left;
    struct Node* right;
} Patient;

// Function to create a new Node
Patient* createNode(const char* ID, const char* Name, int Level) {
    Patient* newNode = (Patient*)malloc(sizeof(Patient));
    if (!newNode) {
        printf("ERROR: Memory Allocation Failed\n");
        exit(1);
    }

    strcpy(newNode->ID, ID); // Copy the provided ID into the node's ID field
    strcpy(newNode->Name, Name); // Copy the provided Name into the node's Name field
    newNode->Level = Level; // Set the Critical Level
    newNode->left = newNode->right = NULL; // Initialize left and right pointers to NULL
    return newNode; // Return the newly created node
}

// Insert a new node with given data into the BST
Patient* insert(Patient* root, const char* ID, const char* Name, int Level) {
    if (root == NULL) {
        // Tree is empty, create a new node
        return createNode(ID, Name, Level);
    }

    if (Level < root->Level) {
        // Insert in the left subtree
        root->left = insert(root->left, ID, Name, Level);
    } else if (Level > root->Level) {
        // Insert in the right subtree
        root->right = insert(root->right, ID, Name, Level);
    }
    return root;
}

// Function to search for a Customer in the BST and update their details
void searchAndUpdate(Patient* root, const char* key) {
    if (root == NULL) {
        printf("Customer with ID '%s' not found.\n", key);
        return;
    }

    // Compare the key with the current node's ID
    if (strcmp(root->ID, key) == 0) {
        printf("Customer Found:\n");
        printf("ID: %s \nName: %s \nLevel: %d\n", root->ID, root->Name, root->Level);

        // Prompt the user to update the details
        printf("Enter new Name: ");
        getchar(); // Consume the newline character left by previous input
        fgets(root->Name, sizeof(root->Name), stdin);
        root->Name[strcspn(root->Name, "\n")] = '\0'; // Remove the trailing newline character

        printf("Enter new Critical Level: ");
        scanf("%d", &root->Level);

        printf("Customer details updated successfully.\n");
        return;
    }

    // Traverse the left or right subtree based on the key
    if (strcmp(key, root->ID) < 0) {
        searchAndUpdate(root->left, key); // Search in the left subtree
    } else {
        searchAndUpdate(root->right, key); // Search in the right subtree
    }
}

// Function to find the in-order successor (smallest node in the right subtree)
Patient* getSuccessor(Patient* root) {
    Patient* current = root -> right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete a Node and indicate if deletion was successful
Patient* delNode(Patient* root, const char* key, int* isDeleted) {
    // Base case: If the tree is empty
    if (root == NULL) {
        *isDeleted = 0; // Deletion unsuccessful
        return root;
    }

    // Compare the key with the current node's ID
    if (strcmp(key, root->ID) < 0) {
        // Key is smaller, search in the left subtree
        root->left = delNode(root->left, key, isDeleted);
    } else if (strcmp(key, root->ID) > 0) {
        // Key is larger, search in the right subtree
        root->right = delNode(root->right, key, isDeleted);
    } else {
        // Node to be deleted is found
        *isDeleted = 1; // Mark deletion as successful

        // Case 1: Node has no left child
        if (root->left == NULL) {
            Patient* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Node has no right child
        if (root->right == NULL) {
            Patient* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        Patient* succ = getSuccessor(root); // Find the in-order successor
        strcpy(root->ID, succ->ID);        // Copy the successor's ID
        strcpy(root->Name, succ->Name);    // Copy the successor's Name
        root->Level = succ->Level;         // Copy the successor's Level
        root->right = delNode(root->right, succ->ID, isDeleted); // Delete the successor
    }
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(Patient* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("ID: %s Name: %s Critical Level: %d\n", root->ID, root->Name, root->Level);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(Patient* root) {
    if (root == NULL) {
        return;
    }

    // Print the Node
    printf("ID: %s Name: %s Critical Level: %d\n", root->ID, root->Name, root->Level);

    // Recur on the left Subtree
    preorderTraversal(root->left);

    // Recur on the right Subtree
    preorderTraversal(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(Patient* root) {
    if (root == NULL) {
        return;
    }

    // Recur on the Left Subtree
    postorderTraversal(root->left);

    // Recur on the Right Subtree
    postorderTraversal(root->right);

    // Print the Node
    printf("ID: %s Name: %s Critical Level: %d\n", root->ID, root->Name, root->Level);
}

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the height of the tree
int height(Patient* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    return max(leftHeight,rightHeight) + 1;
}

// Function to print nodes of the tree at a given level
void printGivenLevel(Patient* root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        printf("ID: %s Name: %s Critical Level: %d\n", root->ID, root->Name, root->Level);
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// Function to print nodes of the tree at a given level and save to file
void printGivenLevelToFile(Patient* root, int level, FILE* file) {
    if (root == NULL) return;
    if (level == 1) {
        fprintf(file, "ID: %s Name: %s Critical Level: %d\n", root->ID, root->Name, root->Level);
    } else if (level > 1) {
        printGivenLevelToFile(root->left, level - 1, file);
        printGivenLevelToFile(root->right, level - 1, file);
    }
}

// Level-Order Traversal
void levelorderTraversal(Patient* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    // Open the file for writting
    FILE* file = fopen("hospital_bst.txt", "w");
    if (file == NULL) {
        printf("ERROR: Unable to open file for writting\n");
        return;
    }

    int h = height(root); // Get the height of the tree
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i); // Print each level
    }

    // Close the file
    fclose(file);
    printf("---Level-order Traversal saved to hospital_bst.txt---\n");
}

// Free the allocated memory for the BST
void freeTree(Patient* root) {
    if (root != NULL) {
        freeTree(root -> left);
        freeTree(root -> right);
        free(root);
    }
}

// Helper function to traverse the tree and print critical patients
void traverse(Patient* node, int* found) {
    if (node == NULL) return;

    // Check if the current node has a critical level of 10
    if (node -> Level >= 8) {
        printf("CRITICAL-LEVEL PATIENT: %s, ID: %s, Level: %d\n", node -> Name, node -> ID, node -> Level);
        *found = 1; // Mark that a critical patient is found
    }

    // Recur on the left and right subtrees
    traverse(node -> left, found);
    traverse(node -> right, found);
}

// Function to print all patients with Critical Level >7
void Critical(Patient* root) {
    printf("---Citical-Level Patient (>7)---\n");
    if (root == NULL) {
        printf("No patients in the tree.\n");
        return;
    }

    int found = 0; // Flag to check if any critical patient is found

    // Start the traversal
    traverse(root, &found);

    // If no critical patients were found, print a message
    if (!found) {
        printf("No patients with Critical Level above 7 found.\n");
    }
}

// Function to print all Traversals
void printAll(Patient* root) {
    printf("\n---Inorder Traversal---\n");
    inorderTraversal(root);

    printf("\n---Preorder Traversal---\n");
    preorderTraversal(root);

    printf("\n---Postorder Traversal---\n");
    postorderTraversal(root);

    printf("\n---Level-order Traversal---\n");
    levelorderTraversal(root);
}

int main() {
    Patient* root = NULL;
    int n;
    char ID[20];
    char Name[30];
    int Level;

    while (1) { // Infinite Loop for the Menu
        // Display
        printf("\n---Vinhealth Hospital System---\n");
        printf("1. Insert Patient\n");
        printf("2. Search & Update\n");
        printf("3. Delete Patient\n");
        printf("4. Traversals\n");
        printf("5. Critical-Level Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
        case 1: // Insert Patient
            printf("Enter Patient ID: ");
            scanf("%s", ID);
            getchar(); // Consume the newline character left by scanf
            printf("Enter Patient Name: ");
            fgets(Name, sizeof(Name), stdin);
            Name[strcspn(Name, "\n")] = '\0'; // Remove the trailing newline character
            printf("Enter Critical Level (1-10): ");
            scanf("%d", &Level);
            root = insert(root, ID, Name, Level);
            printf("Patient inserted successfully.\n");
            break;

        case 2: // Search & Update
            printf("Enter Patient ID to search and update: ");
            scanf("%s", ID);
            searchAndUpdate(root, ID);
            break;

        case 3: // Delete Patient
            printf("Enter Patient ID to delete: ");
            scanf("%s", ID);
            int isDeleted = 0;
            root = delNode(root, ID, &isDeleted);
            if (isDeleted) {
                printf("Patient with ID '%s' deleted successfully.\n", ID);
            } else {
                printf("Patient with ID '%s' not found.\n", ID);
            }
            break;

        case 4: // Traversals
            printAll(root);
            break;

        case 5: // Critical-Level Patient
            Critical(root);
            break;

        case 6: // Exit
            printf("Exiting the program. Goodbye!\n");
            freeTree(root); // Free the allocated memory
            exit(0);

        default: // Invalid Choice
            printf("Invalid choice. Please try again.\n");
        }
    }
}