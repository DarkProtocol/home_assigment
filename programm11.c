#include <stdio.h>
#include <cstdlib>
#include <malloc.h>
#include <mylib.h>



int main (void)
{	
	// нужыне перменные
	int symbolsCount = 0;
	bool isThatHex = 1;
	char *string = NULL;

	printf("Input string count:\n");
	scanf("%d", &symbolsCount);

	// выделяем память под string
	string = (char*)malloc( (symbolsCount + 1) * sizeof(char));
	printf("Input string\n");
	scanf("%s", string);

	isThatHex = isHex(string);

	free(string);

	if ( isThatHex )
		printf("It is hex value\n");
	else
		printf("it is not hex value\n" );

	system("pause");

	return 0;

}