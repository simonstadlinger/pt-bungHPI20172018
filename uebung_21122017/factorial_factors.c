#include <stdio.h>
#include <stdlib.h>




int fac(int i){
	int faculty=1;
	int j = 1;	
	for(;j<=i;j++){
		faculty = faculty*j;
	}
	return faculty;
}



int main(int argc, char * argv[]){
	int zahl = atoi(argv[1]);
	printf("%d\n", zahl);
	printf("%d\n", fac(zahl));
	return 0;

}
