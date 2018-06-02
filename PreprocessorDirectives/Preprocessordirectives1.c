//This program demonstrate the use of preprocessor directives
#include <stdio.h>
#define INRANGE(m) (m >= 1 && m <= 12)
#define NEGATIVE(m) (m < 0)
#define ISLOWER(c) (c >= 'a' && c <= 'z')
#define ISUPPER(c) (c >= 'A' && c <= 'Z')
#define ISALPHA(c) (ISLOWER(c) || ISUPPER(c))
#define ISDIGIT(c) (d >= '0' && d <= '9')

int main()
{
    int m, d;
    char c;

    printf("enter an integer corrosponding to the month");
    scanf("%d", &m);

    if (NEGATIVE(m))
    {
        printf("Enter positive month");
    }
    else
    {
        if (INRANGE(m))
        {
            printf("you entered a valid month");
        }
    }
    c = getchar();
    if (ISALPHA(c))
    {
        printf("You entered alphabet");
    }
}