#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float Re;
	float Im;
} complexNumber_t;

complexNumber_t * complexSum (complexNumber_t * firstNumber, complexNumber_t * secondNumber) {

	complexNumber_t * result = (complexNumber_t*) malloc(sizeof(complexNumber_t));
	result->Re = firstNumber->Re + secondNumber->Re;
	result->Im = firstNumber->Im + secondNumber->Im;

	return result;
}

complexNumber_t * complexSub (complexNumber_t * firstNumber, complexNumber_t * secondNumber) {

	complexNumber_t * result = (complexNumber_t*) malloc(sizeof(complexNumber_t));
	result->Re = firstNumber->Re - secondNumber->Re;
	result->Im = firstNumber->Im - secondNumber->Im;

	return result;
}

complexNumber_t * complexDiv (complexNumber_t * firstNumber, complexNumber_t * secondNumber) {

	complexNumber_t * result = (complexNumber_t*) malloc(sizeof(complexNumber_t));

	result->Re = firstNumber->Re * secondNumber->Re + firstNumber->Im * secondNumber->Im; 
	result->Re /= pow(secondNumber->Re, 2) + pow(secondNumber->Im, 2);

	result->Im = firstNumber->Im * secondNumber->Re - firstNumber->Re * secondNumber->Im; 
	result->Im /= pow(secondNumber->Re, 2) + pow(secondNumber->Im, 2);

	return result;
}

complexNumber_t * complexMult (complexNumber_t * firstNumber, complexNumber_t * secondNumber) {

	complexNumber_t * result = (complexNumber_t*) malloc(sizeof(complexNumber_t));

	result->Re = firstNumber->Re * secondNumber->Re - firstNumber->Im * secondNumber->Im; 
	result->Im = firstNumber->Im * secondNumber->Re + firstNumber->Re * secondNumber->Im; 


	return result;
}

int main(void) {

	complexNumber_t * firstNumber = (complexNumber_t*) malloc(sizeof(complexNumber_t));
	complexNumber_t * secondNumber = (complexNumber_t*) malloc(sizeof(complexNumber_t));

	complexNumber_t * sum = (complexNumber_t*) malloc(sizeof(complexNumber_t));
	complexNumber_t * sub = (complexNumber_t*) malloc(sizeof(complexNumber_t));
	complexNumber_t * div = (complexNumber_t*) malloc(sizeof(complexNumber_t));
	complexNumber_t * mult = (complexNumber_t*) malloc(sizeof(complexNumber_t));

	firstNumber->Re = 4;
	firstNumber->Im = 3;

	secondNumber->Re = 2;
	secondNumber->Im = 1;

	sum = complexSum(firstNumber, secondNumber);
	sub = complexSub(firstNumber, secondNumber);
	div = complexDiv(firstNumber, secondNumber);
	mult = complexMult(firstNumber, secondNumber);

	printf("Sum\n");
	printf("%.2f\n", sum->Re);
	printf("%.2f\n", sum->Im);

	printf("\nSub\n");
	printf("%.2f\n", sub->Re);
	printf("%.2f\n", sub->Im);

	printf("\nDiv\n");
	printf("%.2f\n", div->Re);
	printf("%.2f\n", div->Im);

	printf("\nMult\n");
	printf("%.2f\n", mult->Re);
	printf("%.2f\n", mult->Im);

	printf("Valera psina@@@\n");
	
	return 0;
}
