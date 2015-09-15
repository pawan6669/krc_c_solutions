#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"calc.h"

#define MAXOP 100

int main() {
	int type;
	double  op2;
	char s[MAXOP];

	//printf("Entered  %s\n",__func__);
	while ((type = getop(s)) != EOF) {
		//printf("Type:  %c \n",type);
		switch(type) {
			case NUMBER:
				push(atof(s));
				//printf("float value is %s\n",s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push (pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0) 
					push (pop() / op2);
				else
					printf("ERROR: Div by Zero \n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0)
					push (fmod(pop(),op2));
				else
					printf("ERROR: Modulo Zero \n");
				break;
			case SIN:
				//printf("\n The value : %f \n",sin(pop()));
				push(sin(pop()));
				break;
			case EXP:
				push(exp(pop()));
				break;
			case '\n':
				printf("\t %.8g\n",pop());
				break;
			default:
				printf("Unknown command %s\n",s);
				break;
		}
	}
	//printf("Leaving %s \n",__func__);
	return 0;
}
