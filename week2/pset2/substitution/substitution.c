#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// bool mean ------> true / false
bool is_valid_key(string s);

int main(int argc, string argv[])
{
    // print error code.
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // now its valid
        int k = atoi(argv[1]);
        string s = get_string("plaintext: ");
        printf("ciphertext: ");
        // Enctyptting Formula .
for (int i = 0, j = strlen(s); i < j; i++)
    {
    if (isalpha(s[i]))
    {
        if (isupper(s[i]))
        {
            char p = s[i] - 'A';
            char c = ((p + k) % 26) + 'A';
            printf("%c", c);
        }
        else if (islower(s[i]))
        {
            char p = s[i] - 'a';
            char c = ((p + k) % 26) + 'a';
            printf("%c", c);
        }
    }
        // لو حطيت زياده خطا (else)
    //  فيديو احمد السيد المحاضره الثانيه الاسبوع التالت دقيقه : 13

    else
    {
        (printf("%c", s[i]));
    }
    printf("\n");
    return 0;
    }
    }
}
// valid the key
bool is_valid_key(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char ch = s[i];
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

