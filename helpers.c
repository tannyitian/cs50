#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = -1; k < 2; k++)
        {
            if (i + k < 0 || i + k > height - 1)
            {
                continue;

            }
        }

        for (int j = 0; j < width; j++)
        {
            int sBlue = 0;
            int sRed = 0;
            int sGreen = 0;
            float count = 0.00;

            for (int y = -1; y < 2; y++)
            {
                if (j + y < 0 || j + y > width - 1)
                {
                    continue;

                }
                sBlue += image[i + k][j + y].rgbtBlue;
                sRed += image[i + k][j + y].rgbtRed;
                sGreen += image[i + k][j + y].rgbtGreen;
                count++;
            }


            temp[i][j].rgbtBlue = round(sBlue / count);
            temp[i][j].rgbtRed = round(sRed / count);
            temp[i][j].rgbtGreen = round(sGreen / count);
        }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}