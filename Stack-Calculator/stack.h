#define MAXSTACK 20

typedef struct _stack {
	char array[MAXSTACK];
	int top;
} Stack;

void stackInit(Stack *S);
void push(Stack *S, char c);
char pop(Stack *S);
int isEmpty(Stack *S);
