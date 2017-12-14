#include <stdio.h>
#include <stdlib.h>

int primefactors(int i){
	for(int k=2;k<i;k++){
		if(i%k==0){
			return 0;
		}
	}
	return 1;
}

int main(int argc, char * argv[]){
	int i = atoi(argv[1]);
	for(int j=2;j<i;j++){
		if(i%j==0&&primefactors(j)==1){
			printf("%d\n", j);
	
		}
	}
	return 0;
}
