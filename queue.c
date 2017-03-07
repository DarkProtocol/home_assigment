#include <stdio.h>
#include <malloc.h>

#define STACK_UNDERFLOW -101

/*Структура очереди*/
typedef struct {
	int * elements;
	int number;
} Queue;


void queueInit(Queue * queue) {
	queue->elements = malloc(sizeof(int));
	queue->number = 0;
}

void enqueue(Queue * queue, int value) {

	queue->elements = realloc(queue->elements, (queue->number + 1) * sizeof(int));
	queue->elements[queue->number] = value;
	queue->number++;

}

int dequeue(Queue * queue)
{	
	if (queue->number > 0) {
		int returnValue = queue->elements[0];
		queue->number--;

		int i = 0;

		for (i = 0; i < queue->number; i++) {
			queue->elements[i] = queue->elements[i + 1];
		}

		queue->elements = realloc(queue->elements, (queue->number) * sizeof(int));

		return returnValue;
		
	} else {
		exit(STACK_UNDERFLOW);
	}
}

/*Берет врехний стек массива*/
int getTop(Queue * queue) {
	if (queue->number > 0) 
		return queue->elements[queue->number - 1];
	else 
		exit(STACK_UNDERFLOW);
}

/*проверяет стек на пустоту*/
int isEmpty(Queue * queue) {
	if (queue->number > 0) 
		return 0;
	else 
		return 1;
}

/*Печатает стек*/
void printQueue(Queue * queue) {
	if (queue->number > 0) {
		int i = 0;

		for (i = 0; i < queue->number; i++) {
			printf("%d element = %d\n", (i + 1), queue->elements[i]);
		}

	} else {
		printf("Queue is Empty\n");
	}
}

int main() {

	Queue *queue = (Queue*)malloc(sizeof(Queue));

	queueInit(queue);

	enqueue(queue, 20);
	enqueue(queue, 23);
	enqueue(queue, 24);
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printQueue(queue);


	getchar(); getchar();
	return 0;
}
