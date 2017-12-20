#include <stdio.h>
/*#include <matheWunderkiste.h>*/
#include <stdlib.h>



int main(int argc, char * argv[]){
	int i = atoi(argv[1]);
	for(int j=1;j<i;j++){
		if(i%j==0){
			printf("%d\n", j);
		}
	}

}
