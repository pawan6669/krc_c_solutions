/********************************************************
* Program to convert hexadecimal numbers into decimal numbers.
* The input number can have optional 0x, 0X,......
* 
* Parameter:  Hexadecimal number
*
* Output:  Integer value
********************************************************/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_LEN 1000

int main(int argc, char *argv[]) {
char input[MAX_LEN];
int result = 0;
int index;
int temp;

if (argc < 2) {
 printf("Enter an input number \n");
 //exit();
}

//check if the input is more than the string that we can store
if (strlen(argv[1]) > MAX_LEN-1) {
	printf("Sorry! Currently we are limited to %d input characters \n",MAX_LEN-1);
} else {
	strncpy(input, argv[1], MAX_LEN); 
	//Check for the hexadecimal prefix
	if ((input[0] == '0') && ((input[1] == 'x') || (input[1] == 'X'))) {
		index = 2; 
	} else { 
		index = 0;
	}

	for(; index < strlen(input); index++) {
		//check for valid hexadecimal and get the value
		temp = 0;
		if(input[index] >= '0' && input[index] <= '9') {
			temp = input[index] - '0';
		} else if (input[index] >= 'a' && input[index] <= 'f') {
			temp = 10 + input[index] - 'a';
		} else if (input[index] >= 'A' && input[index] <= 'F') {
			temp = 10 + input[index] - 'A';
		} else {
			//Invalid character. 
			printf("Invalid character %c, entered @ %d \n",input[index], index);
			//exit();
			result=0;
			break;
		}
		result = result * 16 + temp;
	}
}	
	printf("Output in decimal is %d \n",result);
	return (result);
}
