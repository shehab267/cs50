#include <cs50.h>
#include <stdio.h>

int factorial (int h);

int main(void)
{
    int h = get_int("What is the Number? ");

    printf("Factorial= %i\n", factorial(h));

}

int factorial (int h)
{
    //* Base Case.
    if (h == 1)
    {
        return 1;
    }
    // calculate the factorial
    return h * factorial(h - 1);

}