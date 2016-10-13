#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void)
{
	int randNumber;
	int userNumber;
	int i;
	randNumber = rand();
	
	for ( i = 1; i <= N; i++ )
	{
		scanf("%d", &userNumber);
		if ( randNumber == userNumber )
			break;
	}
	
	if ( randNumber == userNumber )
		printf("Congratulatios!");
	else
		printf("Repeat please!");
	
	return 0;
}
