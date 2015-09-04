/************************************************
* This program checks if a character present in second string is present in first string 
* and gives out the first character which occurs. 
* 
* Arguments:  input string S1, input string S2
* 
* output:  first position of occurence of character in S2.
*		   -1  if there is no character matching in the two strings
*		   create a character string S1 with character's in S2 removed.
*
************************************************/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_STRING_LEN  1000
#define MAX_ASCII_CHAR  256

int main(int argc, char *argv[]) {
char s1[MAX_STRING_LEN];
char s2[MAX_STRING_LEN];
char output[MAX_STRING_LEN];
bool ascii[MAX_ASCII_CHAR];
bool first_match = false;
int  first_position = -1;
int  j;
int temp;
int index;

if ((argc < 3) || (argc>3))  {
	printf("Exactly 2 arguments required! Please enter the two strings S1 followed by S2 \n");
} else {
	strncpy(s1, argv[1],MAX_STRING_LEN);
	strncpy(s2, argv[2],MAX_STRING_LEN);

	for(temp = 0; temp < MAX_ASCII_CHAR; temp++) {
		ascii[temp] = false;
	}  
	
	for(temp = 0; temp < strlen(s2); temp++) {
		 index = s2[temp];
		 ascii[index] = true;
	}
	
	for (temp=0, j=0; temp < strlen(s1); temp++) {
		index = s1[temp];
		if (ascii[index]) {
			if (!first_match) {
				first_match = true;
				first_position = temp + 1;
				printf("First match occured @ %d",first_position);
			}
		} else {
			output[j++] = s1[temp];
		}
	}
	output[j] = '\0';
	printf(" The trimmed string is %s \n",output);
}
	return( first_position);
		
}
