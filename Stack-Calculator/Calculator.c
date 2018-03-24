#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"


int Evaluate(char ex[]);
int inToPost(char ex[], int len);
int priority(char op);

int main(){
	

	char ex1[10] = "1+2*3";
	char ex2[10] = "(1+2)*3";
	char ex3[17] = "((1-2)+3)*(5-2)";
	
	inToPost(ex1, 5);
	printf("%s\n", ex1);
	
	inToPost(ex2, 7);
	printf("%s\n", ex2);
	
	inToPost(ex3, 15);
	printf("%s\n", ex3);
		
	/* change to postfix
	## input a formula
	## check each thing whether it is a digit or an operand
	## if it is a digit just put
	## if it is an operand, check the priority and use stack to store them
	## print out the result
	
	

	## calculate
	## input a postfix formula
	## check whether it is a digit or an operand
	## if it is a number, put it in a stack
	## if it is not a number, pop out two numbers, calculate and put it in the stack again.
	## until there is no numbers or operands left.
	## print out the result
*/
}


int inToPost(char ex[], int len){
	
	int i, j=0;
	char* postEx;
	char temp;
	Stack S;
	
	stackInit(&S);
	postEx = (char*)malloc(sizeof(len+1));
	
	for(i=0;i<len;i++){
		//	printf("input is %c\n", ex[i]);
		if(isdigit(ex[i])){
			postEx[j] = ex[i];
			j++;
		}
		else {
			switch(ex[i]){
				case '(' :
					push(&S, ex[i]);
					break;
				case ')' :
					while(1){
						temp = pop(&S);
						if(temp == '(') break;
						postEx[j] = temp;
						j++;					
					}
					break;
				case '+': case '-': case '*': case '/' :
									//printf("operand %c is input\n", ex[i]);
					while(!isEmpty(&S) && priority(ex[i]) <= priority(S.array[S.top])){
						postEx[j] = pop(&S);
						j++;
										//printf("%c is not prior than the stack\n", ex[i]);
					}
					push(&S, ex[i]);
					break;
			}
			
		}
	}
	
	while(!isEmpty(&S)){
		postEx[j] = pop(&S);
		j++;
	}
	postEx[j] = '\0';
	strcpy(ex, postEx);


	return 1;

}

int priority(char op){

	switch(op) {
		case '*' :
		case '/' : return 5;
		case '+' :
		case '-' : return 3;
		case '(' : return 1;
	}
		return -1;
		
}
