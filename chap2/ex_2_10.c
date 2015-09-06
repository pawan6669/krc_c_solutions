/**
  * Program to convert upper case to lower case.
  * 
  * Character string 
  */
#include<stdio.h>

void main(int argc, char *argv[]) {
	int i;
	char *p;

	printf("The converted string: \n");

	for (i = 0; i < argc-1; i++) {
		p = argv[i+1];

	    while (*p) {
			printf("%c", (((*p >= 'A') && (*p <= 'Z'))? (*p - 'A' + 'a'):*p));
			p++;
		}
		printf(" ");
	}

	printf("\n");

}

