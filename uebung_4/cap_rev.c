#include<string.h>
#include<stdio.h>
char makecap(char m){
	switch(m){
		case 'a': return 'A'; break;
		case 'b': return 'B'; break;
		case 'c': return 'C'; break;
	}
}

void capreverse(char s[]){
	int c, i, j;
	for(i=0, j = strlen(s)-1; i<j;i++,j--){
		c = makecap(s[i]);
		makecap(s[j]);
		s[i]=s[j];
		s[j]=c;


	}
}




int main(int argc, int argv[]){
	char * prog =argv[0];
	int i = 0;

	if(argv<2){
		printf("usage: %s <string>+ \n", prog);
		return 1;
	}

	for(i = 1; i<argc;i++){
		capreverse(argv[i]);
		printf("%s\n",argv[i]);
	}
}
