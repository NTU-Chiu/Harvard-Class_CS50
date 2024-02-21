# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int height = get_int("Plz input height: ");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i + 1 ; j++) //Notice: "i+1"
        {
            printf("# ");
        }
        printf("\n");
    }
    return 0;
}