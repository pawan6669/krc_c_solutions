/****************
  * This program implements two functions  
  *
  *  print_escape () - This prints newline and tabs explicitly.
  *  escape_char  () - This would convert the backspace and escape characters
  *
  **************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_escape(char *,char *);
void escape_char(char *,char *);

int main(int argc, char *argv[]) {
	int temp;
	char *ostring;
	int method;

	if ( *argv[1] == '1') {
		method = 0;
	} else if ( *argv[1] == '2') {
		method = 1;
	} else {
		printf("This argument is not supported");
		return 0;
	}

	printf("This has %d arguments  \n",argc);
	
	for (temp = 2; temp < argc; temp++) {

		ostring = (char *) malloc(strlen(argv[temp]) + 25);
		if (method) {
			print_escape(argv[temp],ostring);
		} else {
			escape_char(argv[temp],ostring);
		}

		printf("%s ",ostring);
		
		free(ostring);

	}
	printf("\n");
}


void print_escape(char  *istring, char *ostring) {
	//char *ostring = (char *) malloc(strlen(istring) + 25);

	while(*istring) {
		switch(*istring) {
		case '\t':
			*ostring++ = '\\';
			*ostring++ = 't';
			break;
		case '\n':
			*ostring++ = '\\';
			*ostring++ = 'n';
			break;
		default:
			*ostring++ = *istring;

		}
		istring++;

	}
	*ostring = *istring;
	//return ostring;
}

void escape_char(char *istring,char *ostring) {
	//char *ostring = (char *) malloc(strlen(ostring) + 25);

	while(*istring) {
		switch(*istring) {
		case '\\':

			switch(*(++istring)) {

			case 't':
				*ostring++ = '\t';
				break;
			case 'n':
				*ostring++ = '\n';
				break;
			default:
				*(ostring++) = '\\';
				*(ostring++) = *istring;
			}
			break;
		default:
			*(ostring++) = *istring;

		}

		istring++;
	}
	*ostring = *istring;
	//return ostring;
}

