#include <string.h>
#include <stdio.h>

int main(){

    int c;
    int woerter =0, zeilen=0, zeichen=0;
    int was_space =1;

    while ((c=getchar()) != EOF) {
        if (c> (int)' ' && was_space==1){
            woerter ++;
            zeichen ++;
            }
        else if (c==(int)'\n'){
            zeilen ++;
            zeichen ++;
            }           
        else
            zeichen ++;
        was_space = (int)(c <= (int)' ');
            }
    printf(" %d %d %d" ,zeilen, woerter, zeichen);
    return 0;
}
