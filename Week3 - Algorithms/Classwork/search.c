# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int number[] = {20, 500, 10, 5, 100, 1, 50};
    int n = get_int("Target Number: ");
    int array_length = sizeof(number)/ sizeof(number[0]); // "sizeof" return the SIZE( in byte ) of the array
    for (int i = 0; i < array_length; i++)
    {
        if (number [i] == n)
        {
            printf("Found %d in location %d\n", n, i);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}