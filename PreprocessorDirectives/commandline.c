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