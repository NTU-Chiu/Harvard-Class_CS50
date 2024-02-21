#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Use roundf, otherwise it will only take integer: 3.666 -> 3; roundf(3.666) -> 4;
            int temp = roundf((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);
            image[h][w].rgbtRed = temp;
            image[h][w].rgbtGreen = temp;
            image[h][w].rgbtBlue = temp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sepiaRed = roundf(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue);
            int sepiaGreen = roundf(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue);
            int sepiaBlue = roundf(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int center_line = (width / 2); //(600/2)
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < center_line; w++)
        {
            int tempRed = image[h][w].rgbtRed;
            int tempGreen = image[h][w].rgbtGreen;
            int tempBlue = image[h][w].rgbtBlue;

            // Swap: -1 是因為zero index: 從0開始到599
            image[h][w].rgbtRed = image[h][width - 1 - w].rgbtRed;
            image[h][width - 1 - w].rgbtRed = tempRed;

            image[h][w].rgbtGreen = image[h][width - 1 - w].rgbtGreen;
            image[h][width - 1 - w].rgbtGreen = tempGreen;

            image[h][w].rgbtBlue = image[h][width - 1 - w].rgbtBlue;
            image[h][width - 1 - w].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; //= image[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w].rgbtRed = image[h][w].rgbtRed;
            copy[h][w].rgbtGreen = image[h][w].rgbtGreen;
            copy[h][w].rgbtBlue = image[h][w].rgbtBlue;
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float divisor = 1.0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            if ((h == 0 && w == 0) || (h == (height - 1) && w == 0) || (h == 0 && w == (width - 1)) ||
                (h == (height - 1) && w == (width - 1)))
            {
                divisor = 4.0;
            }
            else if ((h == 0 && 0 < w && w < (width - 1)) || (h == (height - 1) && 0 < w && w < (width - 1)) ||
                     (w == 0 && 0 < h && h < (height - 1)) || (w == (width - 1) && 0 < h && h < (height - 1)))
            {
                divisor = 6.0;
            }
            else
            {
                divisor = 9.0;
            }

            for (int k = -1; k < 2; k++) // -1, 0, +1
            {
                for (int m = -1; m < 2; m++)
                {
                    if ((0 <= (w + k)) && ((w + k) < width) && ((0 <= (h + m)) && ((h + m) < height)))
                    {
                        sumRed += copy[h + m][w + k].rgbtRed;
                        sumGreen += copy[h + m][w + k].rgbtGreen;
                        sumBlue += copy[h + m][w + k].rgbtBlue;
                    }
                }
            }
            image[h][w].rgbtRed = roundf(sumRed / divisor);
            image[h][w].rgbtGreen = roundf(sumGreen / divisor);
            image[h][w].rgbtBlue = roundf(sumBlue / divisor);
        }
    }
    return;
}
