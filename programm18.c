#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float Re;
	float Im;
} complexNumber;

complexNumber * complexSum (complexNumber * firstNumber, complexNumber * secondNumber) {

	complexNumber * result = (complexNumber*) malloc(sizeof(complexNumber));
	result->Re = firstNumber->Re + secondNumber->Re;
	result->Im = firstNumber->Im + secondNumber->Im;

	return result;
}

complexNumber * complexSub (complexNumber * firstNumber, complexNumber * secondNumber) {

	complexNumber * result = (complexNumber*) malloc(sizeof(complexNumber));
	result->Re = firstNumber->Re - secondNumber->Re;
	result->Im = firstNumber->Im - secondNumber->Im;

	return result;
}

complexNumber * complexDiv (complexNumber * firstNumber, complexNumber * secondNumber) {

	complexNumber * result = (complexNumber*) malloc(sizeof(complexNumber));

	result->Re = firstNumber->Re * secondNumber->Re + firstNumber->Im * secondNumber->Im; 
	result->Re /= pow(secondNumber->Re, 2) + pow(secondNumber->Im, 2);

	result->Im = firstNumber->Im * secondNumber->Re - firstNumber->Re * secondNumber->Im; 
	result->Im /= pow(secondNumber->Re, 2) + pow(secondNumber->Im, 2);

	return result;
}

complexNumber * complexMult (complexNumber * firstNumber, complexNumber * secondNumber) {

	complexNumber * result = (complexNumber*) malloc(sizeof(complexNumber));

	result->Re = firstNumber->Re * secondNumber->Re - firstNumber->Im * secondNumber->Im; 
	result->Im = firstNumber->Im * secondNumber->Re + firstNumber->Re * secondNumber->Im; 


	return result;
}

int main(void) {

	complexNumber * firstNumber = (complexNumber*) malloc(sizeof(complexNumber));
	complexNumber * secondNumber = (complexNumber*) malloc(sizeof(complexNumber));

	complexNumber * sum = (complexNumber*) malloc(sizeof(complexNumber));
	complexNumber * sub = (complexNumber*) malloc(sizeof(complexNumber));
	complexNumber * div = (complexNumber*) malloc(sizeof(complexNumber));
	complexNumber * mult = (complexNumber*) malloc(sizeof(complexNumber));

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
	
	printf("\nValera Psina\n");

	getchar();
	getchar();
	return 0;
}
