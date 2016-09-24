#include <cs50.h>
#include <stdio.h>
#include <string.h>

//prototype
int getSum(int digit);
bool checksum(char *number);

const int CARD_MAX_LENGTH = 16;

int main(void)
{
    printf("Number: ");
    long long cardNum = GetLongLong();
 
    // Convert the cardNum to a string of digits
    char cardStr[CARD_MAX_LENGTH];
    sprintf(cardStr, "%lld", cardNum);
    int lenght = strlen(cardStr);
    
    // Now check for card number types
    if (lenght < 13 || lenght > 16 || lenght == 14)
        printf("INVALID\n");
    else if (cardStr[0] == '4' && checksum(cardStr))
        printf("VISA\n"); 
    else if (cardStr[0] == '3' && (cardStr[1] == '4' || cardStr[1] == '7') && checksum(cardStr))
        printf("AMEX\n");
    else if (cardStr[0] == '5' && (cardStr[1] >= '1' || cardStr[1] <= '5') && checksum(cardStr))
        printf("MASTERCARD\n");
    else
        printf("INVALID\n");
    
    return 0;
}

int getSum(int digit)
{
    return (digit / 10) + (digit % 10);
}

bool checksum(char *number)
{
    int digit;
    bool odd = true;
    
    int sum = 0;

    // Run backwards from the last character
    for (int i = strlen(number) - 1; i >= 0; i--)
    {
        digit = number[i] - '0';
    
        sum += odd? digit : getSum(digit * 2);
        odd = !odd;
    }
    
    // If congruent to modulo 10 - correct
    if (!(sum % 10))
        return true;
    else
        return false;
}
