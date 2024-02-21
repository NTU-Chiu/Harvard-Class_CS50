#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    typedef struct node
    {
        int number;
        struct node *next;
    }
    node;

    node *list = NULL; // 用來存取串列的開頭位置

    for (int i = 1; i < argc; i++)
    {
        node *n = malloc(sizeof(node)); //分配到的12bytes，目前為garbage value. 用來暫存讀進來的值
        if (n == NULL)
        {
            printf("malloc error.\n");
            return 1;
        }
        // // i = 0;
        // (*n).number = atoi(argv[i]); //根據指標箭頭到達其中的4bytes位置, 將該位置放入數字
        // (*n).next = NULL;
        // list = n; //將暫存於n的指標 = 開頭指標list

        // // i = 1;
        // (*n).number = atoi(argv[i]);
        // (*n).next = list; // 要將i = 1 的指標指向 i = 0
        // list = n;

        n -> number = atoi(argv[i]);
        // Prepend node to list
        n -> next = list; // 要將i = 1 的指標指向 i = 0
        list = n;
        printf("%i\n", n -> number);
    }

    // print out every list value
    node *temp_pointer = list;
    while(temp_pointer != NULL)
    {
        printf("%i\n", temp_pointer -> number);
        temp_pointer = temp_pointer -> next;
    }

    // Free memory: 像是SWAP杯子裡的水一樣，要有一個暫存地"temp_next"
    node *temp_pointer2 = list;
    while (temp_pointer2 != NULL)
    {
        node *temp_next = temp_pointer2 ->next;
        free(temp_pointer);
        temp_pointer2 = temp_next;
    }
}
