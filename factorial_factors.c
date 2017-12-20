#include <stdio.h>
#include <stdlib.h>

long long primfak(long long z){
	for (int i= 2; i<=z; i++){
		while (z>1 && z%i==0) {
			printf("%d\n",i);
			z = z/i;
		}
	}
return 0;

}

long long fak(int a){
	long long j=1;
	for (int k=1; k <= a; k++){
		j = j*k;
		}
return j;
}


int main(int argc, const char * argv[]) {

//printf("Die Primfaktorzerlegung von %d! ist:\n", atoi(argv[1])
long long a = fak(atoi(argv[1]));
primfak(a);
return 0;

}
