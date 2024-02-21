# include <stdio.h>
# include <string.h> //char *
# include <cs50.h> //string

// --- string vs. character ---
// int main(void)
// {
//     string s = "Hi!"; //cs50幫妳寫好的
//     char c = 'h'; //單個字元用單引號, 結尾沒有NUL字元

//     printf("s = %s\n", s);
//     for (int i = 0; i < 100; i++)
//     {
//         printf("s[%i] = %c\n", i, s[i]); // 共四個字元 'H', 'i', '!', '\0'; 超過則會輸出memory中其他東西
//     }
//     printf("c: %c\n", c);
//     return 0;
// }

//
int main(void)
{
    char *pointer = "HI!"; //字串存的是"指標" 也就是第一個字元'H'的位址
    printf("--使用bracket位址找到值: syntactic sugar\n");
    printf("使用趴c [0]: %c\n", *pointer);
    printf("使用趴c [1]: %c\n", *(pointer + 1));
    printf("使用趴c [2]: %c\n", *(pointer + 2));
    printf("使用趴c [3]: %c\n", *(pointer + 3));

    printf("--使用(位址+i)找到下個值: pointer arithmetic\n");
    printf("使用趴s: %s\n", pointer);
    printf("使用趴c [0]: %c\n", pointer[0]);
    printf("使用趴c [1]: %c\n", pointer[1]);
    printf("使用趴c [2]: %c\n", pointer[2]);
    printf("使用趴c [3]: %c\n", pointer[3]);

    printf("--位址:\n");
    printf("使用趴p: %p (只存第一個字元的位址)\n", pointer);
    printf("-利用de-reference operator &:\n");
    printf("&pointer[0]: %p\n", &pointer[0]);
    printf("&pointer[1]: %p\n", &pointer[1]);
    printf("&pointer[2]: %p\n", &pointer[2]);
    printf("&pointer[3]: %p\n", &pointer[3]);
    printf("&pointer: %p (!!這是指標本人的記憶體位址)\n", &pointer);

    return 0;
}
