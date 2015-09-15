/****************
  * This file implements the stack functionality in the calculator program.
  *
  *
  *****************************/
#include<stdio.h>
#include"calc.h"

static unsigned int stack_ptr=0;
static float  stack[MAXSTACK];

void push(float  number) {
	//printf("Entered %s with %d\n",__func__,stack_ptr);
	if(stack_ptr < MAXSTACK) {
		stack[stack_ptr++] = number;
	} else {
		printf("MAX STACK reached \n");
	}	
}

float pop() {
	float number = -1111;

	//printf("Entered %s with %d\n",__func__,stack_ptr);
	if(stack_ptr <= 0) { 
		printf("Stack underflow \n");
	} else {
		number = stack[--stack_ptr];
	}
	return number;
}	

