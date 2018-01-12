# include <stdio.h>
# include <stdlib.h>


void sieb(int array_grenze){
    int kandidaten[array_grenze];
    int i,x, j ;
    for (int i = 1; i<= array_grenze; i++){
        kandidaten[i]= 1 ;
        } 

    for (i = 1; i < array_grenze / 2 ; i++){
        for (j = 1; j < array_grenze / 2; j++){
            x = i + j + 2*i*j;
            if (x <= array_grenze)
                kandidaten[x] = 0;
        }
    }
    
    for (int i = 1; i<= array_grenze; i++){
        if (kandidaten[i]==1)
            printf("%d \n", 2*i +1 );
    }
 }
    

int main (int argc, char * argv[]) {
    int obergrenze = atoi(argv[1]);
    int array_grenze = (obergrenze - 2)/2;
    if (obergrenze > 1)
        printf("%d \n", 2);
    sieb(array_grenze);
    return 0;
}
