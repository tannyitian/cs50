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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])

{
     for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255 )
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
             if (sepiaGreen > 255 )
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
             if (sepiaBlue > 255 )
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
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

Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++) //for each width
        {
            int sumblue = 0;
            int sumred=0;
            int sumgreen = 0;
            float count = 0.00;
            
            for(int k=-1; k<2; k++)
            {
                if (i + k < 0 || i+k > height - 1)
                {
                    continue;
                }
                else
                {
                    for(int u=-1; u<2; u++)
                    {
                        if (j + u < 0 || j+u > width - 1)
                        {
                            continue;

                        }
                        else
                        {
                            sumblue += image[i+k][j+u].rgbtBlue;
                            sumgreen += image[i+k][j+u].rgbtGreen;
                            sumred += image[i+k][j+u].rgbtRed;
                            count ++;

                        }

                    }

                }
            }
            temp[i][j].rgbtBlue = round(blurBlue / count);
            temp[i][j].rgbtRed = round(blurRed / count);
            temp[i][j].rgbtGreen = round(blurGreen / count);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
    return;
}
// void blur(int height, int width, RGBTRIPLE image[height][width])
// {
//     int blurBlue;
//     int blurRed;
//     int blurGreen;
//     float count;
//     RGBTRIPLE temp[height][width];
//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             blurBlue = 0;
//             blurRed = 0;
//             blurGreen = 0;
//             count = 0.00;
//             for (int k = -1; k < 2; k++)
//             {
//                 if (i + k < 0 || i + k > height - 1)
//                 {
//                     continue;
//                 }
//                 for (int h = -1; h < 2; h++)
//                 {
//                     if (j + h < 0 || j + h > width - 1)
//                     {
//                         continue;
//                     }
//                     blurBlue += image[i + k][j + h].rgbtBlue;
//                     blurRed += image[i + k][j + h].rgbtRed;
//                     blurGreen += image[i + k][j + h].rgbtGreen;
//                     count++;
//                 }

//             }
//             temp[i][j].rgbtBlue = round(blurBlue / count);
//             temp[i][j].rgbtRed = round(blurRed / count);
//             temp[i][j].rgbtGreen = round(blurGreen / count);
//         }
//     }

//     for (int i = 0; i < width; i++)
//     {
//         for (int j = 0; j < height; j++)
//         {
//             image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
//             image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
//             image[j][i].rgbtRed = temp[j][i].rgbtRed;
//         }
//     }
//     return;
// }