// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 2000

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node *hashtable[HASHTABLE_SIZE];

int word_count = 0;

bool check(const char *word)
{
    int len = strlen(word);
    char copy[len + 1];

    copy[len] = '\0';

    for(int i = 0; i < len; i++)
    {
        copy[i] = tolower(word[i]);
    }

    int index = hash(copy) % HASHTABLE_SIZE;

    node* head = hashtable[index];

    if (head != NULL)
    {

        for (node* cursor = head; cursor != NULL; cursor = cursor->next)
        {
            if(strcmp(copy, cursor->word) == 0)
            {
                return true;
            }

        }
    }
    return false;
}

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

bool load(const char *dictionary)
{

    FILE* file = fopen(dictionary, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", dictionary);
        return false;
    }

    // set a buffer to store an output word
    char buffer[LENGTH + 1];

    int k = LENGTH + 2;

    while (fgets(buffer, k, file) != NULL)
    {

        buffer[strlen(buffer) - 1] = '\0';

        int index = hash(buffer) % HASHTABLE_SIZE;

    	node* temp = malloc(sizeof(node));

    	if (temp == NULL)
    	{
    	    fclose(file);
    	    return false;
    	}

    	strcpy(temp -> word, buffer);
        temp -> next = hashtable[index];

        hashtable[index] = temp;
        word_count++;
    }

    fclose(file);

    return true;
}

unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor -> next;

            free(temp);
        }
    }
    return true;
}
