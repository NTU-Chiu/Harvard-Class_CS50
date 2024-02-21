#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // If command line input is not one command-line argument
    // argc 是argv的長度
    // argv 在命令列中所輸入的每一個參數，其中第一個元素是程式本身的名稱
    if (argc != 2) // argv[0] = "./a.out"; argv[1] = "card.raw"
    {
        printf("Commannd Line Usage: ./recover <input file> \n");
        return 1;
    }
    // Open input file
    FILE *file = fopen(argv[1], "r");
    // If the file cannot be opened for reading
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    // ptr: the address (of the first byte) of memory =
    // size_t: the size (in bytes) of the type of data = 1?
    // size_t nmemb: the number of those types to read at once = 512?
    // stream: the pointer to a FILE returned by fopen
    BYTE *buffer = malloc(BLOCK_SIZE); // 將BLOCK_SIZE個記憶體留給buffer使用 ?要另為int? char? 到底差別在哪
    int image_count = -1;
    char file_name[9]; // ###.jpg\n 共8個
    int no = 0;
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE) // read 512 unit of size 1 at a time;
    {
        // Find signature: 0xff 0xd8 0xff
        // 命名檔案
        // The start block of new JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            image_count += 1;
            printf("image_count: %d\n", image_count);
            sprintf(file_name, "%03i.jpg", image_count); // 03 意思是數字含三位, 空位補0
            FILE *writer = fopen(file_name, "w");        // "w": 覆寫 // write 512 unit of size 1 at a time;
            fwrite(buffer, 1, BLOCK_SIZE, writer);
            fclose(writer);
            // image_count +=1;
        }
        else
        {
            // 非開頭,屬於剛剛的開頭檔案
            if (image_count != -1)
            {
                // printf("image_count: %d\n", image_count);
                sprintf(file_name, "%03i.jpg", image_count); // 03 意思是數字含三位, 空位補0
                FILE *writer = fopen(file_name, "a");        // "a": append 續寫 // write 512 unit of size 1 at a time;
                fwrite(buffer, 1, BLOCK_SIZE, writer);
                fclose(writer);
            }
            else
            {
                printf("no: %d\n", no);
                no += 1;
            }
        }

        // buffer到底是什麼...
        // printf("%c %c %c ...\n", buffer[0], buffer[1], buffer[2]);
        // int buffer 輸出1016316063 -274670142 -1945466659 ...
        // char buffer 輸出-45 -80 60 ...
        // BYTE buffer 才是對的，自己定義什麼叫BYTE

        // 寫入檔案
        // FILE *writer = fopen(file_name, "wb");
        // fwrite(&buffer, sizeof(buffer), 1, writer);
        // fclose(writer);
    }
    free(buffer);
    fclose(file);
    return 0;
    // printf("%i\n", image_count);
}
