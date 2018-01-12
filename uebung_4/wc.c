#include <stdio.h>

int main(){
    int c;
    int zeilen = 0, worte = 0, zeichen = 0;
    int is_space = 1;

  while ((c = getchar()) != EOF) {
    if ( c == '\n' ){
        zeilen ++;
        zeichen ++;
        is_space = 1;
    }
    else if (c > 32  && is_space == 1 ){
        worte ++;
        zeichen ++;
        is_space = 0;
    }
    else if ( c <= 32){
        is_space = 1;
        zeichen ++;
    }

    else 
        zeichen ++;
  }  
    
 printf("%d %d %d", zeilen, worte, zeichen);
 return 0;
}


