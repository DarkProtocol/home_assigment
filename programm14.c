#include <stdio.h>
#include <string.h> 
#include <malloc.h>
#include <mylib.h>


int main (void)
{
	
	int studentsCount = 0;
	char **students = NULL;
	char whoLost[26] = {};
	int isFind = 1;

	int i = 0;

	printf("Input students count\n");

	/*вводим количество студентов*/
	scanf("%d", &studentsCount);
	/*очитстим поток для gets()*/
	fflush(stdin);

	/*выделяем память и заносим студентов в масси*/

	students = (char**)malloc( studentsCount * sizeof(char*));

	for (  i = 0; i < studentsCount; i++ )
	{	
		/*резервируем память и плюс 1 для закрывающего символа строки*/
		students[i] = (char*)malloc( 26 * sizeof(char) );
		printf("Write name of student: \n");

		gets(students[i]);
		fflush(stdin);
	}

	/*вводим студента, которго ищем и, собственно, ищем его*/
	printf("Input search student\n");
	gets(whoLost);
	isFind = findString(whoLost, students, studentsCount);

	for (  i = 0; i < studentsCount; i++ )
		free(students[i]);

	free(students);
	
	/*если функция вернула 0, значит есть такой студент*/
	if (isFind == 0 )
		printf("Student has founded!\n");
	else
		printf("Student has't founded!\n");

	pause();
	return 0;
}