#include<stdio.h>
#include<stdlib.h>

int main(){
	int c;
	int word_count=1;
	int char_count=0;
	int line_count=0;
	int ifWord=0;
	while((c = getchar()) != EOF ){
		char_count++;
		switch(c){
			case '\n': line_count++; ifWord=1;
				break;
			case ' ': ifWord=1;
				break;
			case '\t': ifWord = 1;
				break;
			default:
				if(ifWord == 1){
					ifWord=0;
					word_count++;
				}		
				break;
		}
	}
	printf("%d, %d, %d\n", line_count, word_count, char_count); 
	return EXIT_SUCCESS;
}
