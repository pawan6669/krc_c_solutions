/*
 * This program is to set the n bits of x from n bits starting at p position * of y.
 *
 * Arguments passed: 
 * Arg1: The bit to be changed
 * Arg2: The position of y from which bits need to be copied
 * Arg3: The number of bits to be copied
 * Arg4: The number from which the bits needs to be copied 
 *
 * Make sure that p>n or Arg2 > Arg3.
 * 
 * Result:  Number with n bits from arg4 with other bits from arg1 unchanged
 * 
 */

#include<stdio.h>
#include<stdlib.h>

int setbits(int,int,int,int);
void print_hex(int);

int main(int argc, char *argv[]) {
	int x,p,n,y;
	int i;
	int result;
	
	if (argc != 5) {
		printf("Number of arguments should be 4 \n");
		printf("Arg1 - The number for which the bits needs to be changed \n");
		printf("Arg2 - The position from which bits need to be copied \n");
		printf("Arg3 - The number of bits to be taken \n");
		printf("Arg4 - The number from which bits need to be taken \n");

	} else {
							
		x = atoi(argv[1]);
		p = atoi(argv[2]);		
		n = atoi(argv[3]);
		y = atoi(argv[4]);

		printf("\n The value of x: ");
		print_hex(x);
		printf("\n The value of y: ");
		print_hex(y);
		printf("\n The value of p =%d, n=%d \n",p,n);
		
		result = setbits(x,p,n,y);
		
		printf(" The modified value of X is %0x \n",result);
		print_hex(result);
		printf("\n");

		result = invert(x,p,n);
		printf(" The modified value of X is %0x \n",result);
		print_hex(result);
		printf("\n");

		result = retrot(x,n);
		printf(" The modified value of X is %0x \n",result);
		print_hex(result);
		printf("\n");

	}

}

void print_hex(int n) {
	int temp;

	temp = n & ~(~0x01);
	n = n>>1;
	if (n)
		print_hex(n);
	printf("%d",temp);
}
	
/* This function is to set rightmost n bits of y at the p position of x */
int setbits(int x,int p,int n,int y) { 
	int result;
	int mask = ~(~0 << n);

	result = ( x & ~(mask << p+1-n)) | (( y & mask) << p+1-n);
    
	return result;
}

int invert(int x, int p, int n) {
	int result;
	int mask;

	mask = ~(~0 << n);
	result = ( x & ~(mask << p+1-n) ) | ( x ^ (mask << p+1-n));

	return result;
}

int retrot(int x, int n) {
	int result;
	result = x >> n;

	return result;
}
