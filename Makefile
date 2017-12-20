TARGETS= factorial_factors primefactors factors 

all: $(TARGETS)

factorial_factors: factorial_factors.c
	gcc factorial_factors.c -o factorial_factors
primefactors: primefactors.c
	gcc primefactors.c -o primefactors

factors: factors.c
	gcc factors.c -o factors

clean:
	rm -f *.exe
	rm -f *.o $(TARGETS)
	rm -f *.out
