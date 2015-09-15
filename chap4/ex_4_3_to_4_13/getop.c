/********************************************************
  * This file is to get the next operand. 
  *
  * 
  *
  *
  *
  ******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"calc.h"


static char buff[MAXCHAR];
static int bufp=0;
//#define IS_LETTER(c)  ((( (c) >= 'a') && ( (c) <= 'z')) || (((c) >= 'A') || ((c) <= 'Z')))
//#define IS_LETTER(c) isalpha(c)
#define IS_UPPER(c) ( ((c) >= 'A') && ((c) <= 'Z' ))
#define IS_LOWER(c) ( ((c) >= 'a') && ((c) <= 'z' ))

#define IS_LETTER(c)  (IS_UPPER(c) || IS_LOWER(c))

int getch(void) {
	char  ch;
	//printf("Entered %s with bufp=%d \n",__func__,bufp);
	ch = (bufp > 0)? buff[--bufp]:getchar();
	//printf("Leaving %s with %c \n",__func__,ch);
	return ch;
}

void ungetch(int c) {
	//printf("Entered %s\n",__func__);
	if (bufp >= MAXCHAR)
		printf("ungetch: too many characters \n");
	else
		buff[bufp++] = c;
}



int getop(char s[]) {
	int i,c,next;
	int oper;

	//printf("Entered %s\n",__func__);
	while ((s[0] = c = getch()) == ' ' || c == 't') 
			;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
		if (IS_LETTER(c)) {
			i=0;
		//printf("what am I: %c \n",c);
			while((c = getch()) && (IS_LETTER(c))) {
				//printf("%c",c);
				s[++i] = c;
			}
			s[++i] = '\0';
			printf("The string %s \n",s);

			if ((strcmp(s,"SIN")) || (strcmp(s,"sin"))) {
				//printf("SIN entered \n");
				return SIN;
			} else if (strcmp(s,"EXP")) {
				//printf("EXP Entered \n");
				return EXP;
			} else {
				//printf("variable entered \n");
				return VAR;
			}
			ungetch(c);
			return (1);

		} else {
			//printf("An operator: %c \n",c);
			return c; //not a number
		}
	}
	i = 0;

	if ((c == '-') || (c == '+')) {
		// Check if this is a unary or an operator
		next = getch();
		if ((!isdigit(next)) && (next!= '.')) {
			ungetch(next);
			return c;
		} else {
			s[++i] = next;
			 c = next;
		}
	}

	if(isdigit(c))  //collect the integer part. 
		while (isdigit(s[++i] = c = getch()));
			;

	if (c == '.') //collect the fractional part.
		while (isdigit(s[++i] = c = getch()));
			;

	s[i] = '\0';
	if (c != EOF) 
		ungetch(c);

	//printf("Leaving %s\n",__func__);
	return NUMBER;
}


int isLetter(int c) {

		return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))); 
}	
