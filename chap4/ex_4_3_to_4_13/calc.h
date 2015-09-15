/***************************
  *
  * This header file is part of calc.h
  *
  * This has macros and function declarations.
  *  
  *
  *
  ************************/

#define MAXSTACK  100
#define MAXCHAR  100
#define NUMBER 0
#define SIN 1
#define EXP 2 
#define VAR 3


/* Functions defined in getop */
int getop(char s[]);
int getch(void);
void ungetch(int );


/* Functions defined in stack */
void push(float);
float pop();

