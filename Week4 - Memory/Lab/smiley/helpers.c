#include "helpers.h"

#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // printf("R: %d, G: %d, B: %d\n", image[h][w].rgbtRed, image[h][w].rgbtGreen, image[h][w].rgbtBlue);
            if (image[h][w].rgbtRed == 0 && image[h][w].rgbtGreen == 0 &&
                image[h][w].rgbtBlue == 0) // Black: 0 0 0; White: 255 255 255
            {
                image[h][w].rgbtRed = 255;
                // printf("R: %d, G: %d, B: %d\n", image[h][w].rgbtRed, image[h][w].rgbtGreen, image[h][w].rgbtBlue);
            }
        }
    }
}
