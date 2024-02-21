#include <stdio.h>
#include <string.h>

int main(void)
{
    char *string1 = "Hi!";
    char *string2 = "Hii";

    if (strlen(string1) != strlen(string2))
    {
        printf("DIFFERENT.\n");
        return 1;
    }
    else
    {
        for (int i = 0, len = strlen(string1); i < len + 1; i++)
        {
            if (string1[i] != string2[i])
            {
                printf("DIFFERENT.\n");
                return 2;
            }
        }
        printf("SAME.\n");
        return 0;
    }
}
