/*********************
 * This program is to analyze a file. 
 * Things this program prints are:
 *  	number of words in file
 *  	number of lines in file
 *  	number of characters in file
 *  	Histogram of word lengths
 *  	Histogram of line lengths
 *  	Additional things that might get added are:
 *  	check if the file is syntactically correct for braces, single and double quotes. 
 *
 *
 * Arguments: File name 
 *
 *
 ************************/


#include<stdio.h>
#include<stdbool.h>

void  file_process(FILE *);

void main (int argc, char *argv[] ) {
	FILE *fd;
	int i;

	if (argc < 2) 
			printf("Minimum of two arguments are required \n");
	else if (argc >= 2 ) {
			for (i=1; i < argc; i++) { 
				fd = fopen(argv[i],"r");
				printf("Analyzing file %s\n",argv[i]);
				file_process(fd);
				fclose(fd);
			}
			
    }
}

void file_process(FILE *fd) {
	int word_num = 0;
	int line_num = 0;
	int char_num = 0;
	bool in_word = false, in_line=false;
	int c,temp;
	int hist_wlen[100], word_len=0;
	int hist_llen[100], line_len=0;

	/*** clean the histogram ***/
   for(temp=0;temp<100;temp++) {
	   hist_wlen[temp]=0;
	   hist_llen[temp]=0;
	}	   

	while( ( c = fgetc(fd))!= EOF) {
		char_num++;line_len++;
		// Check for linecharacters 
		if ( c == '\n') {
				hist_llen[line_len]++;
				line_len=0;
				if (in_word) {
					hist_wlen[word_len]++;
					word_len=0;
				}
				line_num++;
				in_word=false;
		} else if ( (c == ' ') || (c == '\t')) {
				if (in_word) {
					hist_wlen[word_len]++;
					word_len=0;
				}
				in_word=false;
		} else {
			// This is assumed that we are in word.
			if (!in_word) {
				word_num++;
				in_word=true;
				word_len=1;
			} else {
				word_len++;

			}
		}

	}

	printf("EOF value: %d \n",c);
	printf("It has %d characters \n",char_num);
	printf("It has %d words \n",word_num);
	printf("It has %d lines \n",line_num);
	printf("Word lengths in this file: \n");

	for (temp=0;temp<100;temp++) {
			 if (hist_wlen[temp]) {
					 printf("words with %d length: %d\n",temp,hist_wlen[temp]);
			 } 
	}

	printf("Line lengths in this file: \n");
	for (temp=0;temp<100;temp++) {
			 if (hist_llen[temp]) {
					 printf("lines with %d length: %d\n",temp,hist_llen[temp]);
			 } 
	}

}

