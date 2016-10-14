#include <stdio.h>
#include <math.h>


/**
* double binaryToDecimal функция для перевода из двоичной в десятичную СС
* @param double binary двоичное число, которое надо перевести
* @var double binaryNumber - статичное двочиное число для рекурсии
* @var int degree - статичная степень для перевода
* @var double decimalNumber - статичное десятичное число, которое нужно вычислить
* @var double modfHelper - поможет при вычислении разряда
* @return decimalNumber
*/

double binaryToDecimal( double binaryNumber )
{
    static int degree = 0;
    static double decimalNumber = 0;
    double modfHelper = 0;

    binaryNumber /= 10;
    modfHelper = modf( binaryNumber, &binaryNumber );
    modfHelper *= 10;
    decimalNumber += modfHelper * pow( 2, degree );
    degree++;
	if (modfHelper == 0 || modfHelper == 1)
	{
		if (binaryNumber == 0)
			return decimalNumber;
		else
			binaryToDecimal(binaryNumber);
	}
	else
		return -1;
}

int main( void )
{
    double binaryNumber;
    double decimalNumber;

    scanf("%lf", &binaryNumber);
	//Проверка на валдиность числа
	if (binaryNumber > 0)
	{
		decimalNumber = binaryToDecimal(binaryNumber);

		if (decimalNumber != -1)
			printf("%.0lf", decimalNumber);
		else
			printf("Введите корректное число!");

	}
	else
		printf( "Введите число больше нуля!" );

    return 0;
}

