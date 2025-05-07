#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *createNode( int data) {
    node *newNode = (node*)malloc(sizeof(node));

    if(!newNode){
        printf("ERROR: Memmory alloccation failed \n");
        exit(1);
    }

    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

node *Insert(node *root, int data){
    if(root == NULL) { // Tree is empty
        return createNode(data);
    }
    else if(data <= root -> data) {
        root -> left = Insert(root -> left, data);
    }
    else if(data > root -> data) {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

node *search(node* root, int key) {
    if(root == NULL) {
        return 0;
    }
    else if(root -> data == key) {
        
    }
}

int main()
{
    node *root = NULL; // Creating an empty tree

    root = Insert(root, 15);
}