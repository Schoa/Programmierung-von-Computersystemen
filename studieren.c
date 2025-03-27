#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root -> left);
        printf("%d ", root -> key);
        inorder(root -> right);
    }
}

struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> key = val;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        root = getNewNode(val);
    }
    if (root -> key < val)
    {
        root -> right = insert(root -> right, val);
    }
    else if (root -> key > val)
    {
        root -> left = insert(root -> left, val);
    }

    return root;
}

int search(struct node *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root -> key == val)
    {
        return 1;
    }
    if (root -> key < val)
    {
        return search(root -> right, val);
    }
    else
    {
        return search(root -> left, val);
    }
}

struct node *removeNode(struct node *root, int val) {
    if (root == NULL) {
        return NULL; // Value not found
    }

    if (val < root->key) {
        // Value is in the left subtree
        root->left = removeNode(root->left, val);
    } else if (val > root->key) {
        // Value is in the right subtree
        root->right = removeNode(root->right, val);
    } else {
        // Node to be deleted is found
        if (root->left == NULL) {
            // Node with only right child or no child
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Node with only left child
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // Copy the inorder successor's key to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = removeNode(root->right, temp->key);
    }

    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 100);
    root = insert(root, 80);
    root = insert(root, 120);
    root = insert(root, 15);
    root = insert(root, 60);
    root = insert(root, 150);

    printf("Inorder traversal before deletion: ");
    inorder(root);

    printf("\nDeleting 80...\n");
    root = removeNode(root, 80);

    printf("Inorder traversal after deletion: ");
    inorder(root);

    printf("\nDeleting 100...\n");
    root = removeNode(root, 100);

    printf("Inorder traversal after deletion: ");
    inorder(root);

    return 0;
}