// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>
#include<strings.h>
#include "dictionary.h"
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

unsigned int hash(const char *word);
bool load(const char *dictionary);

// Hash table
node *table[N]; // An array of node pointers

int main(int argc, char *argv[])
{
    char *dictionary = argv[1];
    // char *word = argv[2];
    bool loaded = load(dictionary);

    // // Exit if dictionary not loaded
    // if (!loaded)
    // {
    //     printf("Could not load %s.\n", dictionary);
    //     return 1;
    // }


    // int hash_index = 0;
    // node *cursor = malloc(sizeof(node));
    // if (cursor == NULL)
    //     {
    //         printf("Could not allocate memory of cursor.\n");
    //         return false;
    //     }
    // hash_index = hash(word);
    // cursor = table[hash_index];
    // // Go into the list
    // while(strcasecmp(cursor->word, word) != 0)
    // {
    //     cursor = cursor->next;
    //     if (cursor == NULL)
    //     {
    //         printf("No match word.\n");
    //         return 2;
    //     }
    // }
    // printf("Found match word.\n");
    // return 0;

    // size function TODO
    // char *dictionary = argv[1];
    // bool loaded = load(dictionary);
    // int i = 0;
    // node *n = malloc(sizeof(node));
    // if (n == NULL)
    // {
    //     printf("Could not allocate memory of n.\n");
    //     return 2;
    // }

    // for (int j = 0; j < N; j++)
    // {
    //     if (table[j] != NULL)
    //     {
    //         n = table[j];
    //         printf("j = %i\n", j);
    //         printf("word = %s\n", table[j]->word);
    //         printf("p = %p\n", table[j]->next);
    //         while(n != NULL)
    //         {
    //             n = n -> next;
    //             printf("i = %i\n", i);
    //             i+=1;
    //     }
    //     }

    // }
    //  printf("word count = %i\n", i);
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
        return 1;
    }

    while (fscanf(file_pointer, "%s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not allocate node\n");
            return 1;
        }

        strcpy(n->word, word);
        n->next = NULL;

        int table_index = hash(n->word);
        n->next = table[table_index];
        // printf("%i: %s\n", table_index, n->word);
        table[table_index] = n;
        printf("Table renewed.\n");
    }

    // node *m = malloc(sizeof(node));
    // if (m == NULL)
    // {
    //     printf("Could not allocate memory of n.\n");
    //     return 2;
    // }
    // for (int j = 0; j < N; j++)
    // {
    //     m = NULL;
    //     printf("j = %i\n", j);
    //     // printf("p = %p\n", m->next);
    //     m = table[j];
    // }
    fclose(file_pointer);
    return true;
}
