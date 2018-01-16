#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Counts the number of bits set to 1, starting from the top.
   e.g. 10001000 has 1 bit, 11101000 has 3 bits. */
static int count_leading_ones(char c)
{
	int i;
	for (i = 0; i < CHAR_BIT; i++) {
		if (((c >> (CHAR_BIT - i - 1)) & 1) == 0) {
			return i;
		}
	}
	return CHAR_BIT;
}

/* Counts the number of UTF-8 symbols.
   Expects a pointer to valid UTF-8 byte sequence (null-terminated). */
static size_t strlen_utf8(const char *s)
{
	size_t len = 0;
	int is_escape_byte, num_bytes_in_symbol;

	/* Loop until we reach 0 byte at the end of the sequence */
	while (*s != '\0') {
		char current_symbol = *s;

		/* Do bit test on top-most bit (mask = 10000000 in binary) */
		is_escape_byte = current_symbol & 0x80;
		
		if (is_escape_byte != 0) {
			num_bytes_in_symbol = count_leading_ones(current_symbol);
			s += num_bytes_in_symbol;
		}else 
		    s++;
		len++;
	}
	return len;
}

int main(int argc, char *argv[])
{
	int i;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s string1 ...\n", argv[0]);
		return 0;
	}

	for (i = 1; i < argc; i++) {
		char *s = argv[i];
		printf("strlen     (\"%s\") = %zu\n", s, strlen(s));
		printf("strlen_utf8(\"%s\") = %zu\n", s, strlen_utf8(s));
	}
	return 0;
}

