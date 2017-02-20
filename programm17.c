#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

typedef struct {

	/*Входящтие значение*/
	int x;
	int y;
	int * array;
	int ** matrix;
	char * string;

	/*Возвращаемые значения*/
	int arrayCount;
	int matrixCount;
	int stringCount;
	int * values;
	int ** matrixValues;
	int ** stringValues;
} searchType;

int multiSearch(searchType * valeraPes, char type, void * value)
{


	if ( type == 'a' )
	{
		int i = 0;
		int searchValue = (*(int*)value);
		valeraPes->arrayCount = 0;

		for (i = 0; i < valeraPes->x; i++) 
		{
			
			if ( valeraPes->array[i] == searchValue ) {

				/*Обновим счетчики и запишем значения, выделив память*/
				valeraPes->arrayCount++;
				valeraPes->values = realloc(valeraPes->values, sizeof(int) * valeraPes->arrayCount);
				valeraPes->values[valeraPes->arrayCount - 1] = i;
			}
		}

	} else if ( type == 'm' ) {

		int x = 0;
		int y = 0;
		int searchValue = (*(int*)value);
		valeraPes->matrixCount = 0;

		for ( x = 0; x < valeraPes->x; x++ ) {

			for (y = 0; y < valeraPes->y; y++)
			{
				if ( valeraPes->matrix[x][y] == searchValue ) {

					/*Обновим счетчик*/
					valeraPes->matrixCount++;

					/*Выделим память под хранения индексов вхождений*/
					valeraPes->matrixValues = (int**)realloc(valeraPes->matrixValues, sizeof(int*) * valeraPes->matrixCount);
					valeraPes->matrixValues[valeraPes->matrixCount - 1] = (int *)malloc(sizeof(int) * 2);

					/*Запишем индексы вхождений*/
					valeraPes->matrixValues[valeraPes->matrixCount - 1][0] = x;
					valeraPes->matrixValues[valeraPes->matrixCount - 1][1] = y;


				}
					
			}

		}

	} else if (type == 's') {

		char * searchValue = (char *)malloc( sizeof(char) * 0);
		int i = 0;

		/*Запишем значение*/
		while ( *((char*) value + i) != '\0' )
		{
			searchValue = (char *)realloc(searchValue, sizeof(char) * (i + 1));
			searchValue[i] = *((char*) value + i);
			i++;
		}

		/*В конец строки довавим спец символ*/
		searchValue = (char *)realloc(searchValue, sizeof(char) * (i + 1));
		searchValue[i] = '\0';

		if (i != 0) {

			int x = 0;
			int y = 0;

			while ( valeraPes->string[x + i - 1] != '\0' )
			{
				y = 0;
				while (1) 
				{	
					if (searchValue[y] == '\0'){

						/*Обновим счетчик*/
						valeraPes->stringCount++;

						/*Выделим память под хранения индексов вхождений*/
						valeraPes->stringValues = (int**)realloc(valeraPes->stringValues, sizeof(int*) * valeraPes->stringCount);
						valeraPes->stringValues[valeraPes->stringCount - 1] = (int *)malloc(sizeof(int) * 2);

						/*Запишем индексы вхождений*/
						valeraPes->stringValues[valeraPes->stringCount - 1][0] = x;
						valeraPes->stringValues[valeraPes->stringCount - 1][1] = x + i - 1;

						break;

					} else if ( searchValue[y] != valeraPes->string[x + y] ) {
						break;
					}

					y++;
				}

				x++;
			}

		}

	}

	return 0;

}

int main()
{

	srand(time(0));

	int rows = rand() % 5 + 1; /*количество строк*/
	int cols = rand() % 5 + 1; /*Количество колонок*/

	printf("Rows = %d\n", rows);
	printf("Cols = %d\n\n", cols);

	/*Счетчики*/
	int x = 0;
	int y = 0;

	int stringCount = 5;
	int stringSize = 13;

	/*Где будем искать*/
	char stringArray[5][13] = {"PesValeraPes", "BabichPesPes", "KolyanPessss", "NekitPesPess", "PesTuchnyPes"};

	/*Что будем искать*/
	char searchString[4] = "Pes";

	/*Поиск по массиву*/
	searchType * valeraPes = (searchType *)malloc(sizeof(searchType));
	valeraPes->array = (int*)malloc(sizeof(int) * rows);
	valeraPes->x = rows;

	/*срандомим массив и то, что нужно искать*/
	int searchValue = rand() % 3 + 1;

	for (x = 0; x < valeraPes->x; x++)
	{
		valeraPes->array[x] = rand() % 4;
	}


	multiSearch(valeraPes, 'a', &searchValue);

	/*Проверим работу функции*/
	printf("multiSearch for array\nSearch value = %d\n", searchValue);
	printf("Array = { ");
	for ( x = 0; x < valeraPes->x; x++)
	{
		if ( !(x + 1 == valeraPes->x) )
			printf("%d, ", valeraPes->array[x]);
		else
			printf("%d }\n", valeraPes->array[x]);
	}

	printf("values = {");
	for ( x = 0; x < valeraPes->arrayCount; x++)
	{
		if ( !(x + 1 == valeraPes->arrayCount) )
			printf("%d, ", valeraPes->values[x] + 1);
		else
			printf("%d", valeraPes->values[x] + 1);
	}
	printf(" }\n");


	/*Поиск по матрице элемент, который надо найти оставим тем же*/

	printf("\nSearch for matrix \n");
	
	valeraPes->matrix = (int**)malloc(sizeof(int*) * rows);
	valeraPes->y = cols;

	for ( x = 0; x < valeraPes->x; x++)
	{	
		valeraPes->matrix[x] = malloc(sizeof(int) * cols); 
		for ( y = 0; y < valeraPes->y; y++)
		{
			valeraPes->matrix[x][y] = rand() % 4;
			printf("%d ", valeraPes->matrix[x][y]);
		}

		printf("\n");
	}

	multiSearch(valeraPes, 'm', &searchValue);

	/*Выведем результат работы функции*/

	printf("\nSearch return\n");

	for ( x = 0; x < valeraPes->matrixCount; x++)
	{	
		
		printf("row = %d, ", valeraPes->matrixValues[x][0] + 1);
		printf("col = %d;\n", valeraPes->matrixValues[x][1] + 1);
	}

	/*Перейдем к строкам*/
	/*Срандомим номер строки*/
	int stringNumber = rand() % stringCount;

	valeraPes->string = (char *) malloc(sizeof(char) * stringSize);
	for ( x = 0; x < stringSize; x++)
	{
		valeraPes->string[x] = stringArray[stringNumber][x];
	}

	printf("\nCurrent string: %s\n", valeraPes->string);
	printf("Search string: %s\n", searchString);

	multiSearch(valeraPes, 's', &searchString);

	/*Выведем результат функции*/

	for ( x = 0; x < valeraPes->stringCount; x++)
	{	
		
		printf("start = %d, ", valeraPes->stringValues[x][0] + 1);
		printf("end = %d;\n", valeraPes->stringValues[x][1] + 1);
	}

	getchar();
	getchar();
	return 0;

}