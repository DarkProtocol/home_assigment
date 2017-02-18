#include <stdio.h>
#include <malloc.h>

#define STACK_UNDERFLOW -101

/*Структура стека*/
typedef struct {
	int * elements;
	int number;
} Stack;


void stackInit(Stack * stack) {
	stack->elements = malloc(sizeof(int));
	stack->number = 0;
}

void push(Stack * stack, int value) {

	stack->elements = realloc(stack->elements, (stack->number + 1) * sizeof(int));
	stack->elements[stack->number] = value;
	stack->number++;

}

void pop(Stack * stack)
{	
	if (stack->number > 0) {
		stack->elements = realloc(stack->elements, (stack->number - 1) * sizeof(int));
		stack->number--;
	} else {
		exit(STACK_UNDERFLOW);
	}
}

/*Берет врехний элемент стека массива*/
int getTop(Stack * stack) {
	if (stack->number > 0) 
		return stack->elements[stack->number - 1];
	else 
		exit(STACK_UNDERFLOW);
}

/*проверяет стек на пустоту*/
int isEmpty(Stack * stack) {
	if (stack->number > 0) 
		return 0;
	else 
		return 1;
}

/*Печатает весь стек*/
void printStack(Stack * stack) {
	if (stack->number > 0) {
		int i = 0;

		for (i = 0; i < stack->number; i++) {
			printf("%d element = %d\n", (i + 1), stack->elements[i]);
		}

	} else {
		printf("Stack is Empty\n");
	}
}

int main() {

	Stack *stack = (Stack*)malloc(sizeof(Stack));

	stackInit(stack);

	push(stack, 20);
	push(stack, 23);
	pop(stack);
	printStack(stack);

	return 0;
}
