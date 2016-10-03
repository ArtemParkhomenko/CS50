#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//prototype:
void execution (string keyWord);
char caesar(char token, int key);

int main(int argc, string argv[])
{
    string keyWord = "";
    if(argc == 2)
    {
        int length = strlen(argv[1]);
        for(int i = 0; i < length; i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("Your input contains illegal characters.\n");
                return 1;
            }
            else
            {
                keyWord = argv[1];
            }
        }
    }
    else
    {
        printf("Usage ./Caesar <keyWords>\n");
        return 1;
    }
    execution(keyWord);
    return 0;  
}

void execution (string keyWord)
{
    int keyLength = strlen(keyWord); // We check for the length of the keyword and define an array with that length.
    int keyCodes[keyLength]; 
    
    int keyCount = 0;

    for(int i = 0; i < keyLength;i++)
    {
        keyCodes[i] = toupper(keyWord[i]) - 'A'; // The letters in the keyword array, will be converted to numbers
    }
    printf("plaintext: ");
    string text = GetString();
    int textLength = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < textLength; i++)
    {
        if(!isalpha(text[i]))
        {
            printf("%c", text[i]);
        }
        else
        {
            printf("%c", caesar(text[i], keyCodes[keyCount]));
            if(keyCount < keyLength - 1)
            {
                keyCount++;
            }
            else
            {
                keyCount = 0;
            }
        }
    }
    printf("\n");
}

char caesar(char token, int key)
{
    if(islower(token))
    {
        return ((((token - 'a') + key) % 26) + 'a');
    }
    else
    {
        return ((((token - 'A') + key) % 26) + 'A');
    }
}
// All checks in CS50 is accepted. 
// Thanks for the review.