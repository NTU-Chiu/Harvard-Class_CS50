#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = 0;
    int *p = &a;

    printf("The variable:%d\n", a); //0
    //%p 輸出位址
    printf("Use pointer to show address of a: %p\n", p); //0x7fffce49a7ac
    printf("Use ampersand &a to show address of a: %p\n", &a); //0x7fffce49a7ac
    printf("Use ampersand &a to show address of pointer itself: %p\n", &p); //0x7fff067de050
    printf("Use address (provided by pointer) to show what is in this position: %d\n", *p); //0
    //%i 輸出interger; %d 輸出十進制(decimal)的integer
}
