#include <stdio.h>

int main ()
{
    int x;
    double result;
    double number;
    int pow;

    printf("Write your number\n");
    scanf("%lf", &number);
    printf("Write your pow\n");
    scanf("%d", &pow);

    if ( pow >= 0 )
    {
        for ( x = 0; x <= pow; x++ )
        {
            switch(x)
            {
                case 0:
                    result = 1;
                    break;
                case 1:
                    result = number;
                    break;
                default:
                    result *= number;
                    break;
            }
        }

        printf("Result %.2lf\n", result);
    }
    else
        printf( "Your number need nonnegative!" );

    return 0;
}
