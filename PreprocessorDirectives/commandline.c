/*
 * Filename: commandline.c
 * Created Date: Saturday, June 2nd 2018, 11:39:51 pm
 * Author: Vrushab Bayas
 * @description 
 * Print command line arguments
 * Copyright (c) 2018 Your Company
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    printf("Arguments are\n");

    for (i = 0; i < argc; i++)
    {
        printf("Argument %d=%s\n", i, argv[i]);
    }
}