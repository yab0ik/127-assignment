#pragma once

// Structure for a node in the linked list
typedef struct Node {
    char word[50]; // Assuming maximum word length of 50 characters
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(char* word);

// Function to insert a node at the end of the linked list
void insertNode(Node** head, char* word);

// Function to free memory allocated for the linked list
void freeList(Node* head);

Node* initialisation(char filename[]);

Node*  wordspredicted(Node* head, char* startChar); 




