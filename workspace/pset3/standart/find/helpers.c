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
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j<n; j++)
        {
            if(values[j]<values[minIndex])
            {
                minIndex = j;
            }
        }
        int tmp = values[i];
        values[i]=values[minIndex];
        values[minIndex]=tmp;
    }
    return;
}