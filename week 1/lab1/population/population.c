#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int s;
    do
    {
        s = get_int("Start Size: ");
    }
    while (s < 9);

    // Prompt for end size
    int e;
    do
    {
        e = get_int("End Size: ");
    }
    while (e < s);

    //Calculate number of years until we reach threshold
    int years = 0;

    while (s < e)
    {
        s += (s / 3) - (s / 4);
        years++;
    }
    //Print number of years
    printf("Years: %i\n", years);
}
