//main.c (calls functions from adt.c and predict.c)
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "predict.h"

int main()
{
    char startChar[50]; // Start character for prediction

    int validInput = 0;

    while (!validInput)
    {
        printf("Enter a word with minimum 3 characters starting with the lowercase letter 'd' or 'p' for prediction: ");
        if (scanf("%49s", startChar) != 1)
        {
            printf("Invalid input. Please enter a valid word.\n");
            // Clear input buffer
            while (fgetc(stdin) != '\n');
        } 
        else 
        {
            validInput = 1;
        }
    }
     // Read words from dictionary.txt and insert them into the linked list
    Node* head = initialisation("dictionary.txt");
    //function to findmatching words using startChar
    Node* matchingWords =  wordspredicted(head, startChar);
    Node* temp = matchingWords;

    if (matchingWords == NULL)
    {
        printf("No matching words found.Ensure input fits the parameters\n");
        return 0;
    }

    printf("Predicted words starting with '%s':\n", startChar);
    while (temp != NULL)
    {
        printf("%s\n", temp->word);
        temp = temp->next;
    }

    // // Free memory allocated for the 2 linked list
    freeList(head);
    freeList(matchingWords);


    return 0;
}


