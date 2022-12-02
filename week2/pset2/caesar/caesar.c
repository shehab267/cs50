#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool is_valid_key(string s);

int main(int argc, string argv[])
{
    // get the right key
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // get plaintext
        string s = get_string("plaintext: ");
        // print ciphertext.
        printf("ciphertext: ");
        int k = atoi(argv[1]);
        // Encrypting cipher.
        // Ci = (Pi + k) %26
        for (int i = 0, j = strlen(s); i < j; i++)
        {
            if (isalpha(s[i]))
            {
                // Encrypt the Capital letter.
                if (isupper(s[i]))
                {
                    char p = s[i] - 'A';
                    char c = ((p + k) % 26) + 'A';
                    printf("%c", c);
                }
                // Encrypt the lowercase.
                else if (islower(s[i]))
                {
                    char p = s[i] - 'a';
                    char c = ((p + k) % 26) + 'a';
                    printf("%c", c);
                }
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        return 0;
    }
}
// valid the key.
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

