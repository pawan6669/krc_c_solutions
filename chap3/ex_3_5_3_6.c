/*************************
  *  This program is to print the number n in character form.
  *  Input:  
  *		first argument  - number to be converted
  *		second argument - min number of bits in the output.
  *     third argument - Base number to be represented in`
  *
  ****************************************************************/

#include<stdio.h>
#include<string.h>
//#include<ctype.h>

#define MAXBITS  100

void myitoa(int, char *,int,int);
void reverse(char *, char *);
int myatoi(char *);

int main(int argc, char *argv[]) {
	int number;
	int minBits;
	int base;
	char string[MAXBITS];

	if (argc != 4) {
		printf("This program exactly takes 4 arguments. \n");
	} else {
		number = myatoi(argv[1]);
		minBits = myatoi(argv[2]);
		base = myatoi(argv[3]);

		if (minBits < strlen(argv[1]) + 1) {
			printf("The number takes min %d characters. So some characters might be trimmed \n",strlen(argv[1])+1);
	    } else {
			myitoa(number, string, minBits, base);
			printf("The number is %s \n",string);
		}
	}
}


void myitoa(int number, char  *str, int minBits,int base) { 
	
	int temp = 0;
	int index=0;
	char  tempBuffer[MAXBITS];

	while(number) {
		temp = number % base;
		number = number / base;

		switch(temp) {
			case 10:
				tempBuffer[index++] = 'A';
				break;
			case 11:
				tempBuffer[index++] = 'B';
				break;
			case 12:
				tempBuffer[index++] = 'c';
				break;
			case 13:
				tempBuffer[index++] = 'D';
				break;
			case 14:
				tempBuffer[index++] = 'E';
				break;
			case 15:
				tempBuffer[index++] = 'F';
				break;
			default:
				tempBuffer[index++] = temp + '0';
		}
	}
	
	while(index < minBits+1) {
		tempBuffer[index++] = '0';
	}
	tempBuffer[index] = '\0';

	reverse(tempBuffer, str);
}


void reverse(char *src,char  *dst) {
	int temp =0;
	int len = strlen(src);

	for (temp = 0; temp <= len; temp++) {
		dst[temp] = src[len-1-temp];
	}
	dst[temp] = '\0';
	//printf("\n src is %s\n",src);
	//printf("\n dst is  %s\n",dst+1);
}

int myatoi(char *string) {
	int number = 0;

	while(*string) {
		number = *(string++) - '0' + number * 10;
	}
	return number;
}

