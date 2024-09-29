// predict.c (Initialisation Function & wordspredicted Function)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "adt.h"


Node* initialisation(char filename[])// initialisation function to read words from dictionary.txt and insert them into the linked list
{
    assert(filename != NULL);
    Node* head = NULL;
    FILE* file = fopen(filename, "r");
    assert(file != NULL && "Failed to open file");

    char word[50];
    while (fgets(word, sizeof(word), file) != NULL)
    {
        // Remove trailing newline character
        size_t len = strlen(word);
        if (len > 0 && word[len - 1] == '\n')
        {
            word[len - 1] = '\0';
        }
        insertNode(&head, word); // Insert the word into the list
    }

    assert(head != NULL);

    fclose(file);
    return head;
}

Node* wordspredicted(Node* head, char* startChar) // function to findmatching words using startChar and return a linked list of matching words
{
    if (strlen(startChar) < 3)
    {
        return NULL;// for inputs with less then 3 characters empty linklist
    }

    assert(head != NULL);

    Node* matchingHead = NULL;
    Node* matchingTail = NULL;

    Node* temp = head;
    while (temp != NULL)
    {
        if (strncmp(temp->word, startChar, strlen(startChar)) == 0)// compares the characters from the input to the words in the linked list
        { 
            // Create a new node for the matching word
            Node* newNode = createNode(temp->word);
            assert(newNode != NULL);
            // Insert the new node at the end of the matching linked list
            if (matchingHead == NULL)
            {
                matchingHead = newNode;
                matchingTail = newNode;
            }
            else
            {
                matchingTail->next = newNode;
                matchingTail = newNode;
            }
        }
        temp = temp->next;
    }

    // Return the new linked list of matching words
    return matchingHead;
}