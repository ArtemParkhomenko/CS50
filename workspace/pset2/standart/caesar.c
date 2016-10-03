#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//prototype:
void execution (int key);

int main(int argc, string argv[])
{
    int key = 0;
    if(argc == 2 && atoi(argv[1])>=0)
    {
        key = atoi(argv[1]); // Converted from string to int. 
    }
    else if (argc == 2 && atoi(argv[1])<0)
    {
        printf("Usage ./Caesar <key> must be positive\n");
        return 1;
    }
    else
    {
        printf("Usage ./Caesar <key>.\n");
        return 1;
    }
    execution(key);
    return 0;  
}

void execution (int key)
{
    printf("plaintext: ");
    string text = get_string();
    int length = strlen(text);
    printf("ciphertext: ");
    for(int i = 0; i < length; i++)
    {
        if(isalpha(text[i])) // "isalpha" - checking on the alphabet.  https://reference.cs50.net/ctype/isalpha
        {
            if(islower(text[i])) // "islower" - cheking on the lower case. https://reference.cs50.net/ctype/islower
            {
                printf("%c", ((((text[i] - 'a')+key)%26)+'a'));
            }
            else
            {
                printf("%c", ((((text[i] - 'A')+key)%26)+'A'));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
// All checks in CS50 is accepted. 
// Thanks for the review.