#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get user input
    int h;
    do
    {
        h = get_int("Heigh: ");

    }
    while (h < 1 || h > 8);

    for (int i = 0; i < h; i++)
    {
        // print hashes
        for (int r = 0; r < h; r++)
        {
            if (i + r < h - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        // New row
        printf("\n");
    }

}
