#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // primit user for his Name
    string x = get_string("What is your name? ");

    printf("Hello, %s.\n", x);
}