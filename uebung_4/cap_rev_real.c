<<<<<<< HEAD:uebung_4/cap_rev.c
/*argv* cap_rev.c
* reverse string in place, change letters to uppercase*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
=======
<<<<<<< HEAD
/* AP 5-sep-12	reverse.c				*/
/*		Reihenfolge einer Zeichenkette umkehren	*/
=======
/* cap_rev.c
* reverse string in place, change letters to uppercase*/
>>>>>>> 95a34e1ad6d6e11304b16ecf5ddb6fa7362d3144

# include <string.h>
# include <stdio.h>
>>>>>>> 7bcdd8293a2cf0924564fa486b34d767f209f806:uebung_4/reverse.c

/* reverse a string in place */
void reverse( char s[] ) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i]; s[i] = s[j]; s[j] = c;
	}
}

<<<<<<< HEAD
=======
void uppercase(char s[]) {
    for (int i=0; s[i]!='\0'; i++) {
        if (s[i]>='a' && s[i]<='z'){
            s[i] = s[i] -32; }
    }
}
<<<<<<< HEAD:uebung_4/cap_rev.c

void our_toupper(char s[] ){
    for (int i = 0; s[i] != '\0'; i++){
        s[i]= toupper(s[i]);
     }
 }

=======
>>>>>>> 95a34e1ad6d6e11304b16ecf5ddb6fa7362d3144
>>>>>>> 7bcdd8293a2cf0924564fa486b34d767f209f806:uebung_4/reverse.c
int main( int argc, char * argv [] ) {
	char * prog = argv[0];
	int i = 0;

	if (argc < 2 ) {
		printf("usage: %s <string>+\n", prog );
		return 1;
	}
<<<<<<< HEAD
	for (i = 1; i < argc; i++) {
		printf("%s - \t", argv[ i ]);
		reverse( argv[ i ] );
		printf("%s\n", argv[ i ]);
	}
	return 0;
}
		

	
=======
	for (i = argc-1; i>0; i--) {
		reverse( argv[ i ] );
       // uppercase( argv[ i ] );
        our_toupper( argv[i]);
        printf("%s \n", argv[ i ] );
	}
	return 0;
}
>>>>>>> 95a34e1ad6d6e11304b16ecf5ddb6fa7362d3144
