#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new node with given data into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        // Tree is empty, create a new node
        return createNode(data);
    }

    if (data < root->data) {
        // Insert in the left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // Insert in the right subtree
        root->right = insert(root->right, data);
    }
    // If data is equal, do not insert duplicates (optional)
    return root;
}

// Search for a value in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Free the allocated memory for the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    } 
}

int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value
    int key = 40;
    Node* found = search(root, key);
    if (found != NULL)
        printf("Element %d found in the BST.\n", key);
    else
        printf("Element %d not found in the BST.\n", key);

    // Free memory
    freeTree(root);

    return 0;
}
