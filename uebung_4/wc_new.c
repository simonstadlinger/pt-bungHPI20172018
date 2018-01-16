#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    int c;
    int woerter =0, zeilen=0, zeichen=0;
    int was_space =1;

    while ((c=getchar()) != EOF) {
        if (c> 32 && was_space==1){
            woerter ++;
            zeichen ++;
            }
        else if (c==(int)'\n'){
            zeilen ++;
            zeichen ++;
            }           
        else
            zeichen ++;
        was_space = (int)(c<33);
            }
    printf(" %d %d %d" ,zeilen, woerter, zeichen);
    return EXIT_SUCCESS;
}
