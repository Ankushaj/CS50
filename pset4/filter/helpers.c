#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           int grey = round((image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue) / 3.0);

           image[i][j].rgbtRed = grey;
           image[i][j].rgbtGreen = grey;
           image[i][j].rgbtBlue = grey;
        }
    }
}

int capped(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = capped(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            sepiaGreen = capped(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            sepiaBlue = capped(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int temp_red=image[i][j].rgbtRed;
            int temp_green=image[i][j].rgbtGreen;
            int temp_blue=image[i][j].rgbtBlue;

            image[i][j].rgbtRed=image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen=image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue=image[i][width - 1 - j].rgbtBlue;

            image[i][width - 1 -j].rgbtRed=temp_red;
            image[i][width - 1 - j].rgbtGreen=temp_green;
            image[i][width - 1 - j].rgbtBlue=temp_blue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            float counter = 0.00;

            for (int m = -1; m < 2; m++)
            {
                if (i + m < 0 || i + m > height - 1)
                {
                    continue;
                }

                for (int n = -1; n < 2; n++)
                {
                    if (j + n < 0 || j + n > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i + m][j + n].rgbtBlue;
                    sumGreen += image[i + m][j + n].rgbtGreen;
                    sumRed += image[i + m][j + n].rgbtRed;
                    counter++;
                }
            }
            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
}
