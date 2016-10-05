/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first = 0, last = n;
    if(n==0)
    {
        return false;
    }
    else if(values[0]>value)
    {
        return false;
    }
    else if(values[n-1]<value)
    {
        return false;
    }
    while(first<last)
    {
        int mid=first+(last-first)/2;
        if(value <= values[mid])
        {
            last = mid;
        }
        else
        {
            first=mid+1;
        }
    }
    if (values[last]==value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm
    int temp, item;
    for (int i = 1; i < n; i++)
    {
        temp = values[i];
        item = i-1;
        while(item >= 0 && values[item] > temp) 
        {
            values[item + 1] = values[item]; 
            values[item] = temp;
            item--;
        }
    }
    return;
}
