/*
 * Filename: preprocessor2.c
 * Created Date: Sunday, June 3rd 2018, 9:37:12 am
 * Author: vrushb bayas
 * @description
 * Accept one string and two  characters replcae first charater with second character in the string  
 * Copyright (c) 2018 Your Company
 */

#include <stdio.h>
#include <string.h>

//function declaration
char *replace(char *, char *, char *);

//Entery point function
int main(int argc, char *argv[])
{
    char *string;
    char *first, *second;
    char *newStr;
    if (argc <= 1)
    {
        printf("Enter argument from command line\n");
        return -1;
    }
    string = argv[1];
    first = argv[2];
    second = argv[3];

    newStr = replace(string, first, second);
    printf("%s\n", newStr);
    return 0;
}

char *replace(char *str, char *first, char *second)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == *first)
        {
            str[i] = *second;
            i++;
        }
        i++;
    }
    return str;
}