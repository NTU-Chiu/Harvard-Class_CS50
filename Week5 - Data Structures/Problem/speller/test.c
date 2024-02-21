// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

#include "dictionary.h"
unsigned int hash(const char *word);

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

node *table[26];

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

int main(int argc, char *argv[])
{
    char *dictionary = argv[1];
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
    }
    fclose(file_pointer);
    // for (int i = 0; i < 26; i++)
    // {
    //     printf("%i: %s\n", i, table[i]->word);
    // }

    //Check the strings are linked
    node *n2 = malloc(sizeof(node));
    if (n2 == NULL)
    {
        printf("Could not allocate node\n");
        return 1;
    }
    n2 = table[2]->next;
    printf("%s\n", n2->word);

    return 0;
}
