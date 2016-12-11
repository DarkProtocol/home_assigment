

void pause ()
{	
	char i = 0;
	printf("\nPress any key to close");
	scanf("%d", &i);

	return;
}

/*функция переводит строку в нижиний регситр*/

void toLowerCase (char * string)
{
	unsigned short int i = 0;

	if ( *(string) != '\0')
	{
		while ( 1 )
		{

			if ( *(string + i) == '\0' )
				break;

			if ( *(string + i) >= 'A' && *(string + i) <= 'Z' ) 
				*(string + i) += 32;

			i++;

		}
	}

	return;
}


/*функция возвращает строку в нижнем регистре, но не изменяет ее*/
char getLowerCase (char c)
{
	
	if ( c >= 'A' && c <= 'Z' ) 
		c += 32;

	return c;
			
}

/*функция переводит в верхний регистр*/

void toUpperCase (char * string)
{
	unsigned short int i = 0;

	if ( *(string) != '\0')
	{

		while ( 1 )
		{

			if ( *(string + i) == '\0' )
				break;

			if ( *(string + i) >= 'a' && *(string + i) <= 'z' ) 
				*(string + i) -= 32;

			i++;

		}

	}

	return;
}

char getUpperCase ( char c )
{
	if ( c >= 'a' && c <= 'z' ) 
		c -= 32;

	return c;
}


/*проверка на 16ричное число*/

int isHex ( char *string )
{
	unsigned short int i = 0;
	short int result = 1;


	if ( *(string) != '\0' && *(string) == '0' && *(string + 1) == 'x' )
	{

		toUpperCase(string);

		while ( 1 )
		{

			if ( *(string + i) == '\0' )
				break;

			if ( !( *(string + i) >= 'A' && *(string + i) <= 'Z' || *(string + i) >= '0' && *(string + i) <= '9' ) )
			{
				result = 0;
				break;
			}

			i++;

		}

	}
	else
		result = 0;

	return result;

}

/*возрастающая ли последовательность */

int isAscStringOrder (char * string)
{
	unsigned short int i = 1;
	char previousChar = *string;
	short int result = 1;

	// вдруг передали конец строки
	if (previousChar != '\0')
	{
		while ( 1 )
		{

			if ( *(string + i) == '\0' )
				break;

			if ( !(*(string + i) >= previousChar ) )
			{

				result = 0;
				break;
			}

			previousChar = *(string + i);
			i++;
		}

	}
	else
		result = 0;

	return result;

}


/*функция нахождение максимальной суммы строки вещественной матрицы*/
float maxMatrixStringNumber ( float **matrix, int rowNum, int colNum )
{

	float maxNumber = 0;
	float currentNumber = 0;
	int x = 0;
	int y = 0;

	for ( x = 0; x < rowNum; x++ )
	{
		for ( y = 0; y < colNum; y++ )
			currentNumber += matrix[x][y];

		if ( currentNumber > maxNumber )
			maxNumber = currentNumber;

		currentNumber = 0;

	}

	return maxNumber;

}

/*аналог strlen*/
int stringLength ( char * string )
{
	int i = 0;
	while ( *(string + i) != '\0' )
		i++;

	return i;
}


/*аналог strcmp*/

int stringCompare ( char * string1, char * string2 )
{
	int i = 0;

	while( 1 )
	{	
		/*Если код первого больше кода второго*/
		if ( *(string1 + i) > *(string2 + i) )
		{
			return 1;
			break;
		}

		/*Если код первого меньше кода второго*/
		else if ( *(string1 + i) < *(string2 + i) )
		{	

			return -1;
			break;
		}

		/*Если у первой строки или у второй конец*/
		else if ( *(string1 + i) == '\0' && *(string2 + i) == '\0' )
		{
			return 0;
			break;
		}

		i++;
	}

}

/*функция для поиска строк
возвращает номер строки*/

int findString ( char * string, char **searchArray, int number )
{
	int x = 0;
	char isEqually = 1;

	for ( x = 0; x < number; x++ )
	{
		isEqually = stringCompare(string, searchArray[x]);

		if (isEqually == 0)
			break;
	}

	return isEqually;

}

/*Переводит символ в число*/

int charToInt ( char number )
{
	switch (number)
	{
		case '0':
			return 0;
			break;

		case '1':
			return 1;
			break;

		case '2':
			return 2;
			break;

		case '3':
			return 3;
			break;

		case '4':
			return 4;
			break;

		case '5':
			return 5;
			break;

		case '6':
			return 6;
			break;

		case '7':
			return 7;
			break;

		case '8':
			return 8;
			break;

		case '9':
			return 9;
			break;

		default:
			return -1;
			break;
	}
}


/*функция переводит из строки в числа*/
int* stringToInteger (char* numbersString, int numberCount)
{	
	int i = 0;
	int charCount = stringLength(numbersString);

	int numbers[numberCount];

	/*Коээффицент умножения*/
	int multiplier = 1;

	/*Считает счеткк массива*/
	int numbersArrayCount = numberCount;

	/*перменная ошибки, если символ  был не числом*/
	char notError = 1;

	/*текущий символ в итерации*/
	char currentChar = '\0';

	/*переберем наоборот, чтобы использовать множитель*/
	for ( i = charCount - 1; i >= 0; i-- )
	{	
		currentChar = *(numbersString + i);

		/*Если конец числа, на новую итерацию*/
		if ( currentChar == ' ' || currentChar == '.' )
		{	
			notError = 0;
			numbersArrayCount--;
			numbers[numbersArrayCount] = 0;
			multiplier = 1;
			continue;
		}

		/*Если не конец числа, продолжаем веселье*/
		else 
		{

			if ( notError && currentChar >= '0' && currentChar <= '9' )
			{
				numbers[numbersArrayCount] += charToInt(currentChar) * multiplier;
				multiplier *= 10;
			}
			else
			{
				numbersArrayCount++;
				continue;
			}

		}

		int* p = numbers;

		return p;

	}
}
