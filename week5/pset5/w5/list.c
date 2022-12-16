#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // free size for 3 int
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    // initialize lis of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
/*
    // List of 4 Num.
    int *temp = malloc(4 * sizeof(int));
    if (temp == NULL)
    {
        return 1;
    }
    // Copy the DATA from list to temp.

    for (int i = 0; i < 3; i++)
    {
        temp[i] = list[i];
    }
*/
    /// using *realloc* function
    int *temp = realloc(list, 4 * sizeof(int));
    if (temp == NULL)
    {
        return 1;
    }

    temp[3] = 4;
    // freeing size
    list = temp;
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(list);
}
