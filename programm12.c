#include <stdio.h>
#include <malloc.h>
#include <mylib.h>

int main (void)
{
	int symbolsCount = 0;
	char *string = NULL;
	char isAsc = 1;

	/*заполняем строку*/
	printf("Input number of char:\n");
	scanf("%d", &symbolsCount);

	string = (char*)malloc( (symbolsCount + 1) * sizeof(char) );

	printf("Input your string:\n");
	scanf("%s", string);

	/*проверяем строку*/
	isAsc = isAscStringOrder(string);

	free(string);
	
	if (isAsc)
		printf("It is ASC order\n");
	else
		printf("It is not ASC order\n");



	pause();
	return 0;
}