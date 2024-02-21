# include <stdio.h>
# include <cs50.h>

void draw(int n);

int main(void)
{
    int height = get_int("Plz input height: ");
    draw(height);
}

void draw(int n)
{
    if (n <= 0)
    {
        return; // 開始往回跑, 跳回Line 19
    } //在CLI 使用debug50 ./filename 可看到每一步驟
    draw(n-1);
    for (int i = 0; i < n; i++) // Q:不理解這裡為何不是 n+1 A:因為n是從1開始，而非從0開始
    {
        printf("# ");
    }
    printf("\n");
}
