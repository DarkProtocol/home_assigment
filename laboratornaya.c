#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <math.h> 


#define BUFFERSIZE 1024

// реверсирую число
int intReverse ( int number )
{	
	
	float help = number;
	float decimal = 0;
	int lastInt = 0;
	float lastFloat = 0;
	int result;
	
	
	while ( help != 0 )
	{	
		help /= 10;
		decimal *= 10;
		decimal += (( help - floor(help) ) * 10);
		lastInt = ( help - floor(help) ) * 10;
		lastFloat = ( help - floor(help) ) * 10;
		
		
		help = floor(help);
		
	}
	
	//девятка выбивается, надо округлить
	if ( lastFloat == 9 || lastFloat == 7 )
		lastInt++;
		
	
	//перезапишем с типизацией
	result = (int) decimal;
	result += -(result % 10) + lastInt;
	return result;
	
}

// из чара в инт
int charToInt( char symbol )
{
	switch (symbol)
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

int main (void)
{
	srand(time(0));

	//для буфера
	char buffer[BUFFERSIZE];
	int charCount = 0;

	// для 4 задания
	char *numbersString = NULL;
	int xCount = 0;
	int error = 1;
	int maxYCount = 0;
	int multiplizer = 1;


	// рандомим строки и столбцы
	int m = rand() % 2 + 3;
	int n = rand() % 2 + 4;

	int x = 0;
	int y = 0;
	int i = 0;

	// для минимальных знаечний
	int minValue = 100;
	int minCount = 0;

	//повторения минимальных значений
	int minRepeatX = 0;
	int minRepeatY = 0;

	int array[m][n];

	int tmp = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	int tmp5 = 0;

	for ( x = 0; x < m; x++ )
	{
		for ( y = 0; y < n; y++ )
		{

			array[x][y] = rand() % 100;

			if ( array[x][y] < minValue )
			{
				minValue = array[x][y];
				minCount = 1;
			}

			else if(array[x][y] == minValue)
				minCount++;

		}
	}

	//массив минимальных координат
	int minCoord[minCount * 2];

	//рандомное наполнение

	printf("Number 1\n\n");

	for ( x = 0; x < m; x++ )
	{	
		for ( y = 0; y < n; y++ )
		{
			printf("%d\t", array[x][y]);
		}

		printf("\n");
	}

	// меняем местами 1 и последнюю строку

	for ( y = 0; y < n; y++ )
	{
		tmp = array[0][y];
		array[0][y] = array[m - 1][n - y -1]; 
		array[m - 1][n - y -1] = tmp;

	}

	// вывожу

	printf("\nNumber 2\n\n");

	tmp = 0;

	for ( x = 0; x < m; x++ )
	{	
		for ( y = 0; y < n; y++ )
		{
			printf("%d\t", array[x][y]);

			if ( array[x][y] == minValue )
			{
				minCoord[tmp] = x;
				tmp++;

				minCoord[tmp] = y;
				tmp++;

			}
		}

		printf("\n");
	}

	printf("\n");

	//считаем количество повторенией
	for ( x = 0; x < (minCount * 2 - 2); x += 2 )
	{
		for ( y = 0; y < minCount; y+=2 )
		{
			if ( minCoord[x] == minCoord[y])
				minRepeatX++;
		}
	}

	for ( x = 1; x < (minCount * 2 - 1); x += 2 )
	{
		for ( y = 0; y < minCount; y+=2 )
		{
			if ( minCoord[x] == minCoord[y])
				minRepeatY++;
		}
	}

	int minArrayX = m - minCount + minRepeatX;
	int minArrayY = n - minCount + minRepeatY;

	int minArray[minArrayX][minArrayY];

	// временные перемнный
	tmp = 0;
	tmp2 = 0;
	tmp3 = 0;
	tmp4 = 0;
	tmp5 = 0;


    for (x = 0; x < m; x++ ) 
    {  
       
        tmp4 = 0;
        tmp3 = 0;
       
       // сммотрим совпадениями с координатами минимума, если есть, то прерываем итерацию
        for (tmp = 0; tmp < minCount * 2; tmp+= 2)
            if ( x == minCoord[tmp] ) tmp4 = 1;

       
        if ( tmp4 == 1 ) continue;
 
        for (y = 0; y < n; y++ ) 
        {
           
            tmp5 = 0;

 			// сммотрим совпадениями с координатами минимума, если есть, то прерываем итерацию
            for (tmp = 1; tmp < minCount * 2; tmp+= 2) 
            	if ( y == minCoord[tmp]) tmp5 = 1;

            if ( tmp5 == 1 ) continue;

           // если дошли, то все ок
            minArray[tmp2][tmp3] = array[x][y];
            tmp3++;
        }

        tmp2++;
    }


	printf("Number 3\n");
	// вывод
	for ( x = 0; x < minArrayX; x++ )
	{
		for( y = 0; y < minArrayY; y++ )
		{
			printf("%d\t", minArray[x][y]);
		}

		printf("\n");
	}

	// номер 4


	/*сколько будет символов*/
	printf("\n\nInput string!\n");
	charCount = strlen(fgets(buffer, BUFFERSIZE , stdin));

	numbersString = (char *)malloc(charCount * sizeof(char));

	do
	{
		*(numbersString + i) = *(buffer + i) ;
		i++;
	}
	while ( *(buffer + i) != '\0' );

	i = 0;
	// есть ли в конце точка
	while ( *(numbersString + i ) != '\0' )
	{
		if ( *(numbersString + i ) == '.' )
		{	
			error = 0;
			break;
		}
		i++;
	}

	// переберем на наличие не тех символов
	for ( i = 0; i < charCount; i++ )
	{	
		if( !(*(numbersString + charCount) == '.' || *(numbersString + charCount) == ',' || *(numbersString + charCount) == ' ' || *(numbersString + charCount) >= '0' || *(numbersString + charCount) <= '9') )
		{
			error = 1;
			break;
		}
	}


	if ( !error )
	{
		//начинаем парсить
		// почсичтаем количество строк
		i = 0;
		while ( *(numbersString + i ) != '.' )
		{
			if ( *(numbersString + i ) == ',' )
				xCount++;
			i++;
		}

		//тк в конце точка это тоже строка
		xCount++;

		//запишем в отдельную строку
		int yCount[xCount];

		for ( i = 0; i < xCount; i++ )
			yCount[i] = 0;

		// немного формтанем строку
		i = 0;
		tmp = 0;

		while ( *(numbersString + i ) != '.'  )
		{
			if ( *(numbersString + i ) == ',' && *(numbersString + i + 1 ) == ' ' )
			{
				yCount[tmp]++;
				tmp++;
			}

			if (i != 0)
			{
				if ( *(numbersString + i ) == ' ' && *(numbersString + i - 1 ) != ',' )
					yCount[tmp]++;
					
			}

			if ( *(numbersString + i + 1 ) == '.' )
			{
				yCount[tmp]++;
			}

			i++;
		}

		// найдем максимальное количество столбцов
		for ( i = 0; i < xCount; i++ )
		{
			if ( yCount[i] > maxYCount )
				maxYCount = yCount[i];
		}

		printf("\n");

		//сюда распарсим строку

		int stringArray[xCount][maxYCount];

		//заполним массив нулями
		for ( x = 0; x < xCount; x++)
		{
			for (y = 0; y < maxYCount; y++ )
			{
				stringArray[x][y] = 0;
			}
		}

		tmp = charCount - 1; 

		int currentSumbol = 0;

		for ( x = 0; x < xCount; x++)
		{	

			tmp2 = 0;

			for (y = 0; y < maxYCount; y++ )
			{	

				while ( *(numbersString + currentSumbol) != '.')
				{

					tmp3 = 0;
					multiplizer = 1;

					// если дошли до пробела и до конца строки или на начале строки
					if ( *(numbersString + currentSumbol) == ' ' || *(numbersString + currentSumbol) == ',' || currentSumbol == 0 )
					{	

						if ( currentSumbol != 0 )
							currentSumbol++;			

						// если предыдущий символ не был запятой, значит не в начале строки, но возвожно это и начало строки
						if ( currentSumbol == 0 || *(numbersString + currentSumbol - 1) != ',' )
						{	
	
							i = currentSumbol; // вспомогательный счетчик
							while ( 1 )
							{	

								// дошли до конца числа
								if ( *(numbersString + currentSumbol ) == ' ' )
								{
									tmp3 = 1;
									break;
								} 
								

								// дошли до конца строки
								else if( *(numbersString + currentSumbol ) ==  ',' ||  *(numbersString + currentSumbol ) ==  '.')
								{
									//вспомогательная перменная нужна для записи окончания строки
									tmp2 = 1;
									break;
								}

								//запишем число в массив, умноженное на 10 в N степени, чтобы не потерять разряды
								stringArray[x][y] += charToInt( *(numbersString + currentSumbol ) ) * multiplizer;

								// множиетль увеличив в 10 раз
								multiplizer *= 10;

								// увеличим текущий символ на 1
								currentSumbol++;

							} 
						}

					}

					stringArray[x][y] = intReverse(stringArray[x][y]);

					// если дошли до конца
					if ( tmp2 || tmp3 )
					{
						break;
					}

				}

				// если дошли до конца
				if ( tmp2 )
					break;

			}
		}

		printf("\nNumber 4\n");

		for ( x = 0; x < xCount; x++)
		{
			for (y = 0; y < maxYCount; y++ )
			{
				printf("%d ", stringArray[x][y]);
			}

			printf("\n");
		}

		//переходим к умножению матриц

		// для начала проверим, можем ли перемножить
		if ( minArrayX == maxYCount )
		{


        // Непосредственно умножаем матрицы
	    // создаем итоговую матрицу

		int resultMatrix[minArrayX][maxYCount];

        for ( x = 0; x < minArrayX; x++ )
         {

            //Обнуляем итоговую матрицу
            for( y = 0; y < maxYCount; y++ )
            {
                resultMatrix[x][y] = 0;
            }

            tmp = 0;
            tmp2 = 0;
            y = 0;

            /*
            Делаем бесконечный цикл, но потом его сами прервем
            */
            while ( 1 )
            {

            	/*
            	К ткущему элементу итоговой матрицы текущей строки и текущего 
				столбца второй матрицы прибавляем умножение элемента первой матрицы
				текущей строки и столбца и элемента второй второй матрицы
				текущей строки второй матрицы и текущего тсолбца второй матрицы
            	*/
                resultMatrix[x][y] +=
                    minArray[x][tmp] * stringArray[tmp2][y];

                /*
                Проверим дошли ли до конечного столбца первой матрицы
                и до конца строки второй матрицы
                */
                if ( tmp == (minArrayX - 1) && tmp2 == (maxYCount - 1) )
                {
                	/*
                	Смотри, не дошли ли мы до конечного столбцо второй матрицы
                	если нет, то обнуляем счетчик стобца первой матрицы
                	и строку второй матрицы, чтобы продолжить заново умножать,
                	ткже увеличиваем счетчик столбца второй матрицы на 1, 
                	чтобы нас еребросило на новый элемент итоговой матрицы,
                	и чтобы мы умножали уже другой столбец второй матрицы
                	*/
                    if ( y != (xCount - 1) )
                    {
                        tmp = 0;
                        tmp2 = 0;
                        y++;
                    }
                    //Если все же дошли до конца умножения, брейкаем
                    else
                    {
                        break;
                    }
                }
                /*
                Увеличиваем счетчик столбцов первой матрицы 
                и счетчик строк второй матрицы
                */
                else
                {
                    tmp++;
                    tmp2++;
                }

            }
         }

         // разспечатем матрицу
         printf("\n Result Matrix\n");

         for ( x = 0; x < minArrayX; x++ )
         {
         	for ( y = 0; y < maxYCount; y++ )
         	{
         		printf("%d\t", resultMatrix[x][y]);
         	}
         	printf("\n");
         }

		}
		else
			printf("\nIncorrect matrix\n");
	}

	else
		printf("\nIncorrect string\n");
	



	system("PAUSE");
	return 0;
}