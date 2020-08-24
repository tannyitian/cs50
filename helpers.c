#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //make sure that red, green and blue all have the same value
    //then take the average
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            int avg = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sBlue = 0;
            int sRed = 0;
            int sGreen = 0;
            float count = 0.00;

            for (int k = -1; k < 2; k++)
            {
                for (int y = -1; y<2; y++)
                {
                    if (i + k < 0 || i + k > height - 1 || j + y < 0 || j + y > width - 1 )
                    {
                        continue;
                    }
                    sBlue += image[i + k][j + y].rgbtBlue;
                    sRed += image[i + k][j + y].rgbtRed;
                    sGreen += image[i + k][j + y].rgbtGreen;
                    count++;
                }
            }
            temp[i][j].rgbtBlue = round(sBlue / count);
            temp[i][j].rgbtRed = round(sRed / count);
            temp[i][j].rgbtGreen = round(sGreen / count);
        }
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


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int gx[3][3] ={{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] ={{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};



    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sxBlue=0, syBlue = 0, sxRed = 0, syRed = 0, sxGreen = 0, syGreen = 0;
            int rowArray[] = {i-1, i, i+1};
            int colArray[] = {j-1, j, j+1};

            for (int k = 0; k < 3; k++)
            {
                if (rowArray[k] < 0 || rowArray[k] > height - 1)
                {
                    continue;
                }

                for (int y = 0; y < 3; y++)
                {
                    if (colArray[y] < 0 || colArray[y] > width - 1)
                    {
                        continue;
                    }
                    sxBlue += image[rowArray[k]][colArray[y]].rgbtBlue * gx[k][y];
                    sxRed += image[rowArray[k]][colArray[y]].rgbtRed * gx[k][y];
                    sxGreen += image[rowArray[k]][colArray[y]].rgbtGreen *gx[k][y];

                    syBlue += image[rowArray[k]][colArray[y]].rgbtBlue * gy[k][y];
                    syRed += image[rowArray[k]][colArray[y]].rgbtRed * gy[k][y];
                    syGreen += image[rowArray[k]][colArray[y]].rgbtGreen *gy[k][y];

                }
            }
            int edgeBlue = round(sqrt(pow(sxBlue, 2) + pow(syBlue,2)));
            int edgeRed = round(sqrt(pow(sxRed, 2) + pow(syRed,2)));
            int edgeGreen = round(sqrt(pow(sxGreen, 2) + pow(syGreen,2)));


            if(edgeBlue > 255)
            {
                temp[i][j].rgbtBlue = 255;
            }
            else
            {
                temp[i][j].rgbtBlue = edgeBlue;
            }

            if(edgeRed > 255)
            {
                temp[i][j].rgbtRed = 255;
            }
            else
            {
                temp[i][j].rgbtRed = edgeRed;
            }

            if(edgeGreen > 255)
            {
                temp[i][j].rgbtGreen = 255;
            }
            else
            {
                temp[i][j].rgbtBlue = edgeGreen;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
            image[i][j]= temp[i][j];
            image[i][j] = temp[i][j];
        }
    }
    return;
}

