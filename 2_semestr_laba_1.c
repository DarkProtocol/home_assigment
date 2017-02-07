#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXLENGTH 255

/* Тип структуры данных */
typedef struct {
    int number;
    char string[MAXLENGTH];
    float floatNumber;
} readingFile;

int main(int argc, char **argv) {
    
    FILE *fp;
    char fileName[MAXLENGTH];

    /*проверка валидности названия файла*/
    if ( argc != 2 || ((fp = fopen(argv[1], "r+b")) == NULL) ) {

    	printf("Write validate file\n");

    	while ( 1 ) {
    		scanf("%s", fileName);

            /*Если ок, то обрываем цикл*/
    		if ((fp = fopen(fileName, "rb")) != NULL) break;

            /*Если не ок, то продолжаем цикл*/	
    		else printf("Write validate file\n");
    	}

    }

    /*записываем структуру*/
    readingFile *fileRead = malloc(sizeof(readingFile));

    /*Счетчик количества эелементов*/
    int elementsCount = 0;

    while(!feof(fp)) {

        fread(fileRead, sizeof(fileRead), 1, fp);
        printf("%d %s %f\n", fileRead->number, fileRead->string, fileRead->floatNumber);

        elementsCount++;
    }

    /*Установим укащзатель в конец файла, для подсчета размера*/
    fseek(fp, 0, SEEK_END);
    printf("Elements count: %d\n", elementsCount - 1);
    printf("File size: %ld\n bytes", ftell(fp));
	fclose(fp);

    return 0;
}