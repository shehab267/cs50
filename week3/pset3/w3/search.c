#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    typedef struct
    {
        string name;
        string number;
    }
    person;
    // intailisation people.
    person people[3];

    people[0].name = "Ahmed";
    people[0].number = "012123";

    people[1].name = "Ali";
    people[1].number = "010111";

    people[2].name = "Shams";
    people[2].number = "011666";

    for (int i = 0; i < 3; i++)
    {
        if(strcmp("Ahmed", people[i].name) == 0)
        {
            printf("FOUND! NUM: %s\n", people[i].number);
            return 0;
        }
    }
    printf("NOT FOUND!\n");
}