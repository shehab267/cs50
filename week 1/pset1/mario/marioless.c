#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get user input
    int heigh;
    do
    {
        heigh = get_int("Heigh: ");

    }
    while (heigh < 1 || heigh > 8);

    for (int row = 0; row < heigh; row++)
    {
        // print hashes
        for (int column = 0; column < heigh; column++)
        {
            if (row + column < heigh - 1)
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
