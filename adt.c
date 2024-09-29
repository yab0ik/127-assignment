// adt.c (Linked List ADT Implementation & freeList Function)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node {
    char word[50]; // Assuming maximum word length of 50 characters
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* word)
{
    Node* nextNode = (Node*)malloc(sizeof(Node));
    assert (nextNode != NULL);
    strcpy(nextNode->word, word);
    nextNode->next = NULL;
    return nextNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node** head, char* word)
{
    assert(head != NULL);
    Node* nextNode = createNode(word);
    assert(head != NULL);
    if (*head == NULL) 
    {
        *head = nextNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = nextNode;
}

// Function to free memory allocated for the linked list
void freeList(Node* head)
{
    Node* temp;
    while (head != NULL) 
    {
        assert(head->word != NULL);
        temp = head;
        head = head->next;
        free(temp);
    }
}
