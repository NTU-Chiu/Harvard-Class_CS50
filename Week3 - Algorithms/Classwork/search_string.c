# include <stdio.h>
# include <cs50.h>
# include <string.h>
// Use "strcmp" to do string compare, if equal return 0, else +-1;
int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++) // The string length 0-5. if it is 7, it will have "segmentation fault (core dumped)" error
    {
        printf("%d\n", i);
        if (strcmp(s, strings[i]) == 0)
        {
            printf("Found %s at %d\n", s, i);
            return 0;
        }
    }
    printf("Not found");
    return 1;
}