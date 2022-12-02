#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt for input
    int h;
    do
    {
        h = get_int("Heigh: ");

    }
    while (h < 1 || h > 8);

    // hashes formula
    for (int r = 0; r < h; r++)
    {
        for (int b = h - 1; b > r; b--)
        {
            printf(" ");
        }
        // print laft #
        for (int sh = 0; sh <= r; sh++)
        {
            printf("#");
        }
        printf("  ");
          // print right #
        for (int sh = 0; sh <= r; sh++)
        {
            printf("#");
        }

        printf("\n");

    }
}
