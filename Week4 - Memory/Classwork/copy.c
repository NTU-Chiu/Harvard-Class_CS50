// 使用malloc存取記憶體 使用free釋放記憶體
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
// --錯誤版--
//     char *s = get_string("Plz input s:\n");
//     char *t;
//     t = s; //此時t的值:
//     printf("s: %s; t: %s\n", s, t);
//     //將t轉換成大寫
//     t[0] = toupper(t[0]);
//     printf("s: %s; t: %s\n", s, t);
//     printf("s的值(地址): %p\n", s); //0x55dc8aba16b0
//     printf("t的值(地址): %p\n", t); //0x55dc8aba16b0
//     return 0;

//正確版
    char *s = get_string("Plz input s:");
    char *t = malloc(strlen(s + 1)); //記得+1 for NUL character
    // malloc 將n個記憶體留給t使用

    for (int i = 0, len = strlen(s); i < len + 1; i++) //記得+1 for NUL character
    {
        t[i] = s[i];
    }
    printf("s: %s; t: %s\n\n", s, t);

    t[0] = toupper(t[0]);
    printf("After get upper: \ns: %s; t: %s\n", s, t);
    printf("s的值(地址): %p\n", s); //0x556925c326b0
    printf("t的值(地址): %p\n", t); //0x556925c326f0

    free(t);
    return 0;
}
