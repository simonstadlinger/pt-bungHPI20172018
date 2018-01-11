/* cap_rev.c
* reverse string in place, change letters to uppercase*/

# include <string.h>
# include <stdio.h>

/* reverse a string in place */
void reverse( char s[] ) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i]; s[i] = s[j]; s[j] = c;
	}
}

void uppercase(char s[]) {
    for (int i=0; s[i]!='\0'; i++) {
        if (s[i]>='a' && s[i]<='z'){
            s[i] = s[i] -32; }
    }
}
int main( int argc, char * argv [] ) {
	char * prog = argv[0];
	int i = 0;

	if (argc < 2 ) {
		printf("usage: %s <string>+\n", prog );
		return 1;
	}
	for (i = argc-1; i>0; i--) {
		reverse( argv[ i ] );
        uppercase( argv[ i ] );
		printf("%s \n", argv[ i ] );
	}
	return 0;
}
