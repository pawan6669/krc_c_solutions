/**********************************
  * Program to find the position of string t in string S.
  *  
  * Input parameters:
  *     arg1 :  String where the string needs to be searched in
  *     arg2 :  The string which needs to be searched for.
  *
 *  Output parameters: rightmost position of t if present in S, -1 otherwise
 *  
 *****************************************************************/

#include<stdio.h>
#include<string.h>

int findString(char *, char *);
void reverse(char *,char *);

int main(int argc, char *argv[]) {
	char  *s1, *s2;
    int s1index = 0;
    int	s2index = 0;
	int pos = -1;
	int found = 0;

	if (argc != 3) { 
		printf(" This prgram takes in 3 arguments. \n");
	} else {
		s1 = argv[1];
		s2 = argv[2];
		s1index = strlen(s1) - 1;
		//printf("The strings are S1: %s,  S2:%s \n",s1,s2);

		while((s1index >= 0) && (!found)){
			pos = s1index;	
			s2index = strlen(s2) - 1;
			//printf(" The s1 char: %c, s2 char: %c \n",s1[s1index],s2[s2index]);	
			if (s2[s2index] == s1[s1index]) {
				while( (s1index >= 0) && (s2index >= 0) && (s1[s1index] == s2[s2index])) {
					s1index -= 1;
					s2index -= 1;
				}
				//printf("the values are s1index=%d, s2index=%d, pos=%d \n",s1index,s2index,pos);
				if (s2index < 0) {
					found = 1;
					pos = s1index;
				}
			
			}

			s1index = pos - 1;

		}
		
		if (found)
			printf("The string is found @ pos: %d \n",strlen(s1)-pos-1);
		else 
			printf("The string is not found \n");

		printf("Using findstring: \n");
        reverse(argv[1], s1);
        reverse(argv[2], s2);
		printf("The strings are S1: %s,  S2:%s \n",s1,s2);
		printf("the pos returned from findstring:  %d \n",findString(s1,s2));

		//printf("the position is %d \n",strlen(s1)-findString(s1, s2));

	}
}


/* This function identifies string s2 in string s1 from left*/
int findString(char *s1, char *s2) {
	int pos=-1;
	int s1len = strlen(s1);
	int s2len = strlen(s2);
	int found = 0,s1index = 0, s2index = 0;

	while ( (s1index < s1len) && (!found))  {
		pos = s1index;
		s2index = 0;

		if (s1[s1index] == s2[s2index]) {

			while ( (s1index < s1len) && (s2index < s2len) && (s1[s1index] == s2[s2index])) {
				s1index++;
				s2index++;
			}
			if (s2index == s2len) {
				found = 1;
			}
		}
		s1index = pos + 1;
	}

	if (!found) 
		pos = -1;	
	return pos;
}


void reverse(char *src,char  *dst) {
	int temp =0;
	int len = strlen(src);

	for (temp = 0; temp <= len; temp++) {
		dst[temp] = src[len-1-temp];
	}
	dst[temp] = '\0';
	printf("\n src is %s\n",src);
	printf("\n dst is  %s\n",dst+1);
}


