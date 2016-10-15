#include <stdio.h>

void printMatrix( int m, int n, double matrix[m][n] )
{
    int nCount;
    int mCount;

    for( mCount = 0; mCount < m; mCount++ )
    {
        for( nCount = 0; nCount < n; nCount++ )
        {
            printf("%6.2lf\t", matrix[mCount][nCount]);
        }
        printf("\n");
    }

    return;
}

int main (void)
{
    int m, n, m1, n1;
    int mCount, nCount, m1Count, n1Count;

    printf("Write number of lines in first matrix!\n");
    scanf("%d", &m);
    printf("Write number of columns in second matrix!\n");
    scanf("%d", &n);

    printf("Write number of lines in first matrix!\n");
    scanf("%d", &m1);
    printf("Write number of columns in second matrix!\n");
    scanf("%d", &n1);

    if ( n == m1 )
    {
        double firstMatrix[m][n];
        double secondMatrix[m1][n1];
        double resultMatrix[m][n1];

        printf("\nEnter items of first matrix\n");
        //Вводим числа первой матрицы
        for( mCount = 0; mCount < m; mCount++ )
        {

            for( nCount = 0; nCount < n; nCount++ )
            {   printf("%d line %d column\n", mCount + 1, nCount + 1);
                scanf("%lf", &firstMatrix[mCount][nCount]);
            }
        }
        printMatrix( m, n, firstMatrix);
        //Вводим числа второй матрицы
        printf("\nEnter items of second matrix\n");

        for( m1Count = 0; m1Count < m1; m1Count++ )
        {
            for( n1Count = 0; n1Count < n1; n1Count++ )
            {
                printf("%d line %d column\n", m1Count + 1, n1Count + 1);
                scanf("%lf", &secondMatrix[m1Count][n1Count]);
            }
        }

         printMatrix( m1, n1, secondMatrix);



         //Непосредственно умножаем матрицы
         for ( mCount = 0; mCount < m; mCount++ )
         {

            //Обнуляем итоговую матрицу
            for( n1Count = 0; n1Count < n1; n1Count++ )
            {
                resultMatrix[mCount][n1Count] = 0;
            }

            nCount = 0;
            m1Count = 0;
            n1Count = 0;

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
                resultMatrix[mCount][n1Count] +=
                    firstMatrix[mCount][nCount] * secondMatrix[m1Count][n1Count];
                /*
                Проверим дошли ли до конечного столбца первой матрицы
                и до конца строки второй матрицы
                */
                if ( nCount == (n - 1) && m1Count == (m1 - 1) )
                {
                	/*
                	Смотри, не дошли ли мы до конечного столбцо второй матрицы
                	если нет, то обнуляем счетчик стобца первой матрицы
                	и строку второй матрицы, чтобы продолжить заново умножать,
                	ткже увеличиваем счетчик столбца второй матрицы на 1, 
                	чтобы нас еребросило на новый элемент итоговой матрицы,
                	и чтобы мы умножали уже другой столбец второй матрицы
                	*/
                    if ( n1Count != (n1 - 1) )
                    {
                        nCount = 0;
                        m1Count = 0;
                        n1Count++;
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
                    nCount++;
                    m1Count++;
                }

            }
         }

         //Распечатаем итоговую матрицу
         printf("\nMultiplied result\n\n");
         printMatrix( m, n1, resultMatrix );
    }
    else
        printf("Matrix can't be multiplied!");

    return 0;
}
