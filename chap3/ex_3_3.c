/**********************************************************
  * Description: This program is to expand expressions as described below.
  * 		a-z:  abcdef....xyz
  *			a-d-f:  abcdef
  *			-a-f: abcdef
  *  Input: Single argument with stream of characters without spaces
  *  Output:  Expanded stream.
  ********************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int categorize(char);
char *expand(char *);

void main(int argc, char *argv[]) {
char  *outstring;

	if (argc != 2) {
			printf("\n This program supports only one parameter \n");
	} else {
		printf("The input stream is %s \n",argv[argc-1]);
		outstring = expand(argv[argc-1]);
		if(strlen(outstring) != 0)
		printf("The output stream is: \n %s \n",outstring);
	}

}


/* This is the actual function which causes expansion */
char *expand(char *src) {
char temp_char = '\0';
char src_char = '\0';
char dest_char = '\0';
int temp;
int flag = 0;
int oindex = 0;
int mismatch = 0;

char *ostring = (char *) malloc(100 * strlen(src));

for (temp = 0; temp < strlen(src) && (!mismatch) ; temp++) {
	temp_char = *(src + temp);

	if (temp_char == '-') {
		if (src_char) {
			flag = 1;

		} else {
			/* this is the case for prefix or trailing -- */
			ostring[oindex++] = temp_char;		
			
		}	

	} else {
		if (flag) {
			/* Already we are in expansion phase */
        	/* Get the destination character till which we need to expand */
			dest_char = temp_char;
			if (( categorize(src_char) == categorize(dest_char)) && (src_char < dest_char))  {
			// this is where we do the real expansion
				for (src_char += 1;src_char <= dest_char;src_char++) 
					ostring[oindex++] = src_char;
				flag=0;
				src_char = dest_char;
				dest_char = '\0';

			} else {
				printf("Mismatch in character expansion. please check %c-%c",src_char,dest_char);	
				mismatch = 1;
			}

		} else {

			ostring[oindex++] = temp_char;
			src_char = temp_char;

		}

	}
}

/* This means destination character is not found (trailing hiphen) */
if (flag) {
	ostring[oindex++] = '-';
}
	

if (!mismatch) {
ostring[oindex] = '\0';

} else {
ostring[0] = '\0';
}
return  ostring;


}




/* This function would categorize the characters as following:
numeric (0-9): 1
small letters(a-z): 2
Capital Letters(A-Z): 3
*/

int categorize(char c) { 
	int result = -1;

	if ((c >= '0') && (c < '9'))
		result = 1;
	else if (( c >= 'a') && (c <= 'z'))
		result = 2;
	else if (( c >= 'A') && (c <= 'Z'))
		result = 3;
	else 
		result = 4;

	return result;
}
