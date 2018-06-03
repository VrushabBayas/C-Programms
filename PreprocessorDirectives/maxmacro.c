/*
 * Filename: maxmacro.c
 * Created Date: Sunday, June 3rd 2018, 10:27:35 am
 * Author: Vrushab Bayas
 * @descrption
 * write macro to find max from n numbers
 */

#define MAX(a, b) (a > b ? a : b)
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//function declaration
void findMax(int *, int);
//Entery point
int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Enter command line argument\n");
        return -1;
    }
    int *arr;
    int size = atoi(argv[1]);
    int i = 0;

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Unable to allocate memory..!");
        return -1;
    }
    printf("enter elemet in the array:");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    findMax(arr, size);
    return 0;
}

void findMax(int *arr, int size)
{
    int i = 0;
    int max = 0;
    for (i = 0; i < size; i++)
    {
        if (MAX(arr[i], max))
        {
            max = arr[i];
        }
    }
    printf("MAx is:%d\n", max);
}