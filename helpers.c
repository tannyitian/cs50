#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
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
                    sBlue += image[i + k][j + k].rgbtBlue;
                    sRed += image[i + k][j + k].rgbtRed;
                    sGreen += image[i + k][j + k].rgbtGreen;
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
//     RGBTRIPLE temp[height][width];
//     int gx[3][3];
//     int gy[3][3];

//     for (int i = 0; i < 3; i++)
//     {
//         for(int j = 0; j < 3; j++)
//         {
//             if (j == 0)
//             {
//                 if(i==0 || i==2)
//                     gx[i][j] = -1;

//                 else
//                     gx[i][j] = -2;

//             }
//             else if (j == 2)
//             {
//                 if(i==0 || i==2)
//                     gx[i][j] = 1;

//                 else
//                     gx[i][j] = 2;
//             }
//             else
//             {
//                 gx[i][j] = 0;
//             }

//         }
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         for(int j = 0; j < 3; j++)
//         {
//             if (i == 0)
//             {
//                 if(j==0 || j==2)
//                     gy[i][j] = -1;

//                 else
//                     gy[i][j] = -2;

//             }
//             else if (i == 2)
//             {
//                 if(j==0 || j==2)
//                     gy[i][j] = 1;

//                 else
//                     gy[i][j] = 2;
//             }
//             else
//             {
//                 gy[i][j] = 0;
//             }

//         }
//     }

//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             int sxBlue, syBlue = 0;
//             int sxRed, syBlue = 0;
//             int sxGreen, syBlue = 0;
//             float count = 0.00;
//             for (int k = -1; k < 2; k++)
//             {
//                 if (i + k < 0 || i + k > height - 1)
//                 {
//                     continue;
//                 }
//                 for (int y = -1; y < 2; y++)
//                 {
//                     if (j + y < 0 || j + y > width - 1)
//                     {
//                         continue;
//                     }
//                     sBlue += image[i + k][j + y].rgbtBlue * gx[i + k][j + y];
//                     sRed += image[i + k][j + y].rgbtRed * gx[i + k][j + y];
//                     sGreen += image[i + k][j + y].rgbtGreen *gx[i + k][j + y];

//                     count++;
//                 }

//             }
//             temp[i][j].rgbtBlue = round(sBlue / count);
//             temp[i][j].rgbtRed = round(sRed / count);
//             temp[i][j].rgbtGreen = round(sGreen / count);
//         }
//     }

//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
//             image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
//             image[i][j].rgbtRed = temp[i][j].rgbtRed;
//         }
//     }

// }
    return;
}

