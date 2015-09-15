/******************
  * This program is to convert the floating point char strings to float point value
  *
  * input paramter:  char string such as 10.4e-5  15.6e+6
  *
  * output: corresponding floating point values
  ****************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float convert_float(char *);

int main(int argc, char  *argv[]) {
	int temp;

	for (temp = 1; temp < argc; temp++) {
		printf("The character string is %s\n",argv[temp]);
		printf("The corresponsing floating point value:  %f \n",convert_float(argv[temp]));
	}
}

float convert_float(char *str) {
	float number=0,pow=1;
	int sign = 1;
	int dec_flag=0;
	int exp_flag =0;
	int exp_sign = 1;
	int exp_value = 1;
	int exp = 0;
	int start = 0;
	int invalid = 0;
	char ch;

	while ((!invalid) && (*str)) {
		ch = *(str++);
		//printf("characters being parsed: %c \n",ch);
		switch(ch) {
			case 'e': case 'E':
				 exp_flag = 1;
				 break;
			case '-':
				 if (exp_flag)
					exp_sign = -1;
				 else if (!start) {
				 	sign = -1;
					start = 1;
				 } else {
					printf("Invalid - sign");
					invalid = 1;
				 }
				 break;
			case '+':
				 if (exp_flag)
					exp_sign = 1;
				 else if (!start) {
				 	sign = +1;
					start = 1;
				 } else {
					printf("Invalid - sign");
					invalid = 1;
				 }
				 break;
			case '0': case  '1':case '2': case '3': 
			case '4': case  '5':case '6': case '7':
			case '8': case  '9':
				 start = 1;
				 if (exp_flag) {
					exp = exp*10 + ch - '0';
				 } else if (dec_flag) {
				 	number = number * 10 + ch - '0';
					pow = pow * 10;
				 } else {
				 	number = number * 10 + ch - '0';
				 }
				 break;
			case '.':
				 dec_flag = 1;
				 break;
			default:
				printf("Invalid input");
				invalid = 1;
				break;
			}

	//printf("the values parsed exp:%d, num:%f, pow:%f, exp_sign:%d \n",exp,number,pow,exp_sign);
	}
	while(exp--) {
		exp_value = exp_value * 10;
		//printf("exp:%d, exp_value:%d \n",exp,exp_value);
	}

	//printf("the values parsed exp:%d, num:%f, pow:%f, exp_sign:%d \n",exp_value,number,pow,exp_sign);
	if (exp_sign > 0) {
		number = number * exp_value / pow ;
	} else {
		number = number / (pow * exp_value);
	}
	number = number * sign;
	if (!invalid)	
		return number;
	else 
		return -1;
}
