#include"stack.h"

void stackInit(Stack *S){

	S->top = -1;
	
}


void push(Stack *S, char c){

	S->top++;

	if(S->top >= MAXSTACK) {
		printf("Out of range");
	}
	S->array[S->top] = c;
	
}

char pop(Stack *S){

	char returnValue;
	
	if(S->top < 0) {
		printf("Nothing to pop\n");
	}
	
	
	returnValue = S->array[S->top];
	S->top--;
	
	return returnValue;
}

int isEmpty(Stack *S){

	if(S->top < 0) return 1;
	else return 0;

}
