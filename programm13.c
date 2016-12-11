#include <stdio.h>

#include <malloc.h>
#include <mylib.h>

int main (void)
{
	float **matrix = NULL;
	float maxNumber = 0;
	int rowNum = 0;
	int colNum = 0;
	int x = 0;
	int y = 0;

	printf("Input X & Y\n");
	scanf("%d%d", &rowNum, &colNum);

	/*динамиское выделение памяти на матрицу*/
	matrix = (float**)malloc( rowNum * sizeof(float) );
	for ( x = 0; x < rowNum; x++ )
	{
		matrix[x] = (float*)malloc( colNum * sizeof(float) );
	}

	/*ввод чисел матрицы*/
	for ( x = 0; x < rowNum; x++ )
	{

		printf("Row # %d\n", x + 1);

		for ( y = 0; y < colNum; y++ )
		{
			printf("Input col # %d\n", y + 1 );
			scanf("%f", &matrix[x][y]);
		}

	}


	maxNumber = maxMatrixStringNumber ( matrix, rowNum, colNum );

	/*очищаем память*/
	for ( x = 0; x < rowNum; x++ )
	{
		free(matrix[x]);
	}

	free(matrix);

	printf("Max summ = %.2f\n", maxNumber);

	pause();
	return 0;
}