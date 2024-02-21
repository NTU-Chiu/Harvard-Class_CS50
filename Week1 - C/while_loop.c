# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int count = 1;
    int goal = get_int("How many times U want to repeat?");
    while(count <= goal)
    {
        printf("%d \n",count);
        count+=1;
    }
}