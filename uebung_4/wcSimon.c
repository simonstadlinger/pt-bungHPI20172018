#include<stdio.h>
#include<stdlib.h>

int main(){
	int c;
	int word_count=0;
	int char_count=0;
	int line_count=0;
	while((c = getchar()) != EOF ){
		char_count++;
		switch(c){
			case '\n': line_count++;word_count++;
				break;
			case ' ':
			case '\t':
				 
		}
	}
	printf("counted words: %d\n", word_count);
	printf("counted lines: %d\n", line_count);
	printf("counted characters: %d\n", char_count);
	return EXIT_SUCCESS;
}
