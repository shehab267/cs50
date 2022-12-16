#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// Malloc func. is used for holding places in memory ---> #include <stdlib.h>
//dont forget to free the memory at the end.---> free(t)
// We also use if condition for address = 0 == NULL for bugs
// strcpy(t, s); be sure to put 2string first.----> insted of for loop. 20 : 23
int main(void)
{
    char *s = get_string("S: ");
    char *t = malloc(strlen(s) + 1);
    // checking for NULL
    if (t == NULL)
    {
        return 1;
    }

    //for (int i = 0, n = strlen(s); i <= n; i++)
    //{
    //    t[i] = s[i];
    //}
    strcpy(t, s);
    // be sure the user prompt char
    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("S: %s\n", s);
    printf("T: %s\n",t);

    free(t);
}