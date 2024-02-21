#include <stdio.h>
#include <stdlib.h>
// 增加list
int main(void)
{
    int *list = malloc(sizeof(int) * 3);
    if (list == NULL)
    {
        printf("memory is run out of location.");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        list[i] = i+1;
        printf("%i\n", list[i]);
    }

    // int *temp_list = malloc(sizeof(int)*4);
    // for (int i = 0; i < 3; i++)
    // {
    //     temp_list[i] = list[i];
    // }

    //function: realocation, 等同上述註解處
    int *temp_list = realloc(list, 4 * sizeof(int));
    temp_list[3] = 4;
    list = temp_list;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(list);
    return 0;
}
