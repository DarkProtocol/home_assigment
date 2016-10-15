#include <stdio.h>

int main(vaid)
{
    const N;
    int i;
    int plusAmount = 0;
    double arithmeticMean;
    double currentNumber;

    printf("Write amount of numbers!\n");
    scanf("%d", &N);
    double plusNumbers[N];
    printf("Write your numbers!\n");

    for( i = 0; i < N; i++ )
    {
      scanf("%lf", &currentNumber);
      if ( currentNumber > 0 )
      {
          plusNumbers[plusAmount] = currentNumber;
          arithmeticMean += currentNumber;
          plusAmount++;
      }
    }

    arithmeticMean /= plusAmount;

    printf("\nAll plus numbers %d\n", plusAmount);
    printf("The arithmetic mean %.2lf\n", arithmeticMean);

    return 0;
}
