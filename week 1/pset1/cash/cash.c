#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // prompt user for change
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // calculate coins
    int cents = round(dollars * 100);
    // change Calculate
    int coins = 0;
    int domination[] = {25, 10, 5, 1};
    int size = 4;
    for (int i = 0; i < size; i ++)
    {
        coins += cents / domination[i];
        cents %= domination[i];
    }

    printf("%i\n", coins);
}