#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float money;
    int count = 0;
    int leftover;
    
    do
    {
        printf("O hai! How much change is owed? \n");
        money = GetFloat();
    }  
    while (money <= 0);
    
    leftover = round(money * 100);
    
    //Quarters
    count = (leftover/25);
    count = round(count);
    leftover = leftover % 25;
    
    //Dimes
    count = count + (leftover/10);
    count = round(count);
    leftover = leftover % 10;
    
    //Nickels
    count = count + (leftover/5);
    count = round(count);
    leftover = leftover % 5;
    
    //Pennies
    count = count + leftover;
    printf("%d\n", count);
}