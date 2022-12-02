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
    // calculate quarter
    int coins = 0;
    while (cents >= 25)
    {
        cents -= 25;
        coins ++;
    }
    // cal.Dimes
    while (cents >= 10)
    {
        cents -= 10;
        coins ++;
    }
    // cal. nickels
    while (cents >= 5)
    {
        cents -= 5;
        coins ++;
    }
    // Cal. Cents
    while (cents >= 1)
    {
        cents -= 1;
        coins ++;
    }

    printf("%i\n", coins);
}