/* 01-2018	palindrome.c				*/
/*		Überprüfen ob Wörter der Eingabe Palindrome sind	*/

# include <string.h>
# include <stdio.h>

/* reverse a string in place */
int is_palindrome( char s[] ) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		if (s[i] != s[j])
            return 0;
	}
    return 1;
}

int main( int argc, char * argv [] ) {
	char * prog = argv[0];
	int i = 0;

	if (argc < 2 ) {
		printf("usage: %s <string>+\n", prog );
		return 1;
	}
	for (i = 1; i < argc; i++) {
	    if (is_palindrome(argv[i]) == 1)
            printf("YES \n");
        else
            printf("NO \n");
    }
	return 0;
}
