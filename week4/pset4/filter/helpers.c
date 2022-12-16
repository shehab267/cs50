#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
            // print the final image.
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);
            // print the final image.
            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    // Transformation the pixels.
    // 1 2 3 4 ---> _ _ _ _
    //       j      cp
    for (int i = 0; i < height; i++)
    {
        int curpos = 0;
        for (int j = width - 1; j >= 0; j--, curpos++)
        {
            temp[i][curpos] = image[i][j];
        }
    }
    // Copy to the Edited image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    /*
    for each row
    for each col
        set count to 0
        for every neighboring pixel within the radius m in the x direction
            for every neighboring pixel within the radius m in the y direction
                 add the color to the total
                 count++
        final_color = total/count
        setpixel(current x, current y, final_color)
    */
    for (int raw = 0; raw < height; raw++)
    {
        for (int cul = 0; cul < width; cul++)
        {
            int rawcoords[] = {raw - 1, raw, raw + 1};
            int culcoords[] = {cul - 1, cul, cul + 1};
            int count = 0;
            float totalG = 0, totalR = 0, totalB = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {

                    int curRaw = rawcoords[i];
                    int curCul = culcoords[j];

                    if (curRaw >= 0 && curRaw < height && curCul >= 0 && curCul < width)
                    {
                        RGBTRIPLE pixel = image[curRaw][curCul];
                        totalR += pixel.rgbtRed;
                        totalB += pixel.rgbtBlue;
                        totalG += pixel.rgbtGreen;
                        count++;
                    }
                }
            }
            //final_color = total/count
            temp[raw][cul].rgbtRed = round(totalR / count);
            temp[raw][cul].rgbtBlue = round(totalB / count);
            temp[raw][cul].rgbtGreen = round(totalG / count);
        }
    }

    // copy the final image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
