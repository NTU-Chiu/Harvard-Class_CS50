#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// sprintf: print a "formatted string" to a location in a memory.
int main(void)
{
    // char buffer[14];

    // int i = 50;
    // sprintf(buffer, "This is CS%i", i);
    // printf("%s\n", buffer);

    // float f = 50.0;
    // sprintf(buffer, "This is CS%.1f", f);
    // printf("%s\n", buffer);

    // for (int j = 0; j <= 14; j++)
    // {
    //     printf("j = %i: %c\n", j, buffer[j]);
    // }
    int *buffer = malloc(10);
    for (int i = 0; i < 10; i++)
    {
        FILE *writer = fopen("test.txt", "wb");
        buffer[i] = i;
        fwrite(&buffer[i], sizeof(i), 1, writer);
        fclose(writer);
    }
    free(buffer);
}
