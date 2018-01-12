TARGETS= cap_rev.c is_palindrome.c sundarams_sieve.c wc.c 
CFLAGS= -g

all: $(TARGETS)

cap_rev:
	gcc $(CFLAGS) cap_rev.c -o cap_rev 
is_palindrome:
	gcc $(CFLAGS) is_palindrome.c -o is_palindrome

sundarams_sieve:
	gcc $(CFLAGS) sundarams_sieve.c -o sundarams_sieve

wc:
	gcc $(CFLAGS) wc.c -o wc

clean:
	rm -f *.exe
	rm -f *.o $(TARGETS)
	rm -f *.out
