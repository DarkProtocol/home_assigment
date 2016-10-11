
#include <stdio.h>

int main()
{
    int x;
    printf("Print your number\n");

    scanf("%i", &x);
    if ( x > 0 )
    {
        x *= 2;
        printf("\n%i", x);
    }
    else if ( x < 0 )
    {
        x -= 3;
        printf("%i\n", x);
    }
    else if ( x == 0 )
    {
        x = 10;
        printf("%i\n", x);
    }

    return 0;
}
