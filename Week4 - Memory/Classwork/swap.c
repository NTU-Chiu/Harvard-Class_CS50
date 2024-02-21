#include <stdio.h>

// void swap(int *a, int *b);

// int main(void)
// {
//     int x = 1;
//     int y = 2;

//     printf("x is %i, y is %i\n", x, y);
//     printf("x = %p, y = %p\n", &x, &y);
//     swap(&x, &y);
//     printf("---Swap:\nx is %i, y is %i\n", x, y);
//     printf("x = %p, y = %p\n", &x, &y);
//     return 0;
// }

// void swap(int *a, int *b)
// {
//     printf("a = %i, b = %i\n", *a, *b);
//     printf("a = %p, b = %p\n", a, b);
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("---Swap:\n");
//     printf("a = %i, b = %i\n", *a, *b);
//     printf("a = %p, b = %p\n", a, b);
// }

int main(void)
{
    int aa = 1;
    int bb = 2;
    int *a = &aa;
    int *b = &bb;

    printf("a = %i, b = %i\n", *a, *b);
    // printf("a = %p, b = %p\n", &a, &b);
    printf("a = %p, b = %p\n", a, b);
    // a = 1, b = 2
    // a = 0x7ffe2366012c, b = 0x7ffe23660128

    int temp = *a;
    *a = *b;
    *b = temp;
    printf("---Swap:\n");
    printf("a = %i, b = %i\n", *a, *b);
    // printf("a = %p, b = %p\n", &a, &b); // pointer本人的位置
    printf("a = %p, b = %p\n", a, b); // pointer指向的位置 ???為何pointer沒有交換???
    // a = 2, b = 1
    // a = 0x7ffe2366012c, b = 0x7ffe23660128
}
