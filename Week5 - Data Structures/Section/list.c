#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

#define LIST_SIZE 2

bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase:");

        // Add phrase to new node in list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Run out of memory, cannot allocate n.");
            return 1;
        }

        // 將值放入記憶體
        (*n).phrase = phrase; // ->
        (*n).next = NULL; // Reset為預設值而非不動(garbage value)

        // 第一個迴圈: list指向第一個node, 第二個迴圈: (*n).next = 指向第一個node = list
        (*n).next = list;

        // 將現有的n(開頭)指標位置傳給list
        list = n;


        // Visualize list
        visualizer(list);
    }
    // Free all memory used
    if (!unload(list))
    {
    printf("Error freeing the list.\n");
    return 1;
    }

    printf("Freed the list.\n");
}

bool unload(node *list)
{
    node *ptr = list;
    while(list != NULL)
    {
        // ptr有malloc卻沒有被free
        // ==31330== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
        // node *ptr = malloc(sizeof(node));
        // if (ptr == NULL)
        // {
        //     printf("Run out of memory, cannot allocate ptr.");
        //     return false;
        // }
        // ptr = list -> next;
        // free(list);
        // list = ptr;

        ptr = list -> next;
        free(list);
        list = ptr;
    }
    return true;
}
void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");

}
