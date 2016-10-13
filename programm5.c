#include <stdio.h>
#include <math.h>

int main ()
{
    double a, b ,c, D, x1, x2;

    printf("Enter numbers a, b, c\n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    D = b*b - 4*a*c;
    if ( D > 0 )
    {

        x1 = ( -b + sqrt(D) ) / (2*a);
        x2 = ( -b - sqrt(D) ) / (2*a);
        printf( "X1 = %.3lf\n X2 = %.3lf\n", x1, x2);

    }
    else if ( D == 0 )
    {

        x1 = ( -b + sqrt(D) ) / (2*a);
        printf( "X = %.3lf\n", x1 );

    }
    else if ( D < 0 )
    {
        printf("The discriminant is less than zero\n");
    }

    return 0;
}
