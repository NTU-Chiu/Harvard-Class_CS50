// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int count = 0;
// Hash table
node *table[N]; // An array of node pointers

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_index = 0;
    // node *cursor = malloc(sizeof(node));
    // if (cursor == NULL)
    //     {
    //         printf("Could not allocate memory of cursor.\n");
    //         return false;
    //     }
    hash_index = hash(word);
    node *cursor = table[hash_index];
    // Go into the list
    if (cursor != NULL)
    {
        while (strcasecmp(cursor->word, word) != 0)
        {
            cursor = cursor->next;
            if (cursor == NULL)
            {
                // printf("No match word.\n");
                // free(cursor);
                return false;
            }
        }
    }
    // printf("Found match word.\n");
    // free(cursor);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    FILE *file_pointer = fopen(dictionary, "r");
    if (file_pointer == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    while (fscanf(file_pointer, "%s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not allocate node\n");
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        int table_index = hash(n->word);
        n->next = table[table_index];
        table[table_index] = n;
        count += 1;
    }
    fclose(file_pointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // printf("count: %i", count);
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // node *cursor = malloc(sizeof(node));
    // if (cursor == NULL)
    //     {
    //         printf("Could not allocate memory of cursor.\n");
    //         return false;
    //     }
    for (int j = 0; j < N; j++)
    {
        node *cursor = table[j];
        // Go into the list
        while (cursor != NULL)
        {
            node *tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
    return true;
}
