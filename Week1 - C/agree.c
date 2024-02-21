#include <stdio.h>
#include <cs50.h>
// Answer "no" or "yes", it will ask the question again???
int main(void)
{
    char c = get_char("Do U agree?"); // String use double quote ""

    if (c == 'y' || c == 'Y') // One character use single quote ''
    {
        printf("Agreed.\n");
    }
    else if (c == 'n'|| c == 'Y')
    {
        printf("Not Agreed.\n");
    }
    else
    {
        printf("Please answer y/n.\n");
    }
}