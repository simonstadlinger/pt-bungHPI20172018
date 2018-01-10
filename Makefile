TARGETS= factorial_factors primefactors factors 
CFLAGS= -std=gnu99
all: $(TARGETS)

factorial_factors: factorial_factors.c
	gcc $(CFLAGS) factorial_factors.c -o factorial_factors
primefactors: primefactors.c
	gcc $(CFLAGS) primefactors.c -o primefactors

factors: factors.c
	gcc $(CFLAGS) factors.c -o factors

clean:
	rm -f *.exe
	rm -f *.o $(TARGETS)
	rm -f *.out
