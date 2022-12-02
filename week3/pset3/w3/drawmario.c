#include <cs50.h>
#include <stdio.h>

void draw (int h);

int main(void)
{
    int h = get_int("H: ");

    draw(h);

}

void draw (int h)
{
    if (h == 0)
    {
        return;
    }
    draw (h - 1);
    // print #
    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}