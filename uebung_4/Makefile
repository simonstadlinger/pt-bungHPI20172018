TARGETS= cap_rev is_palindrome sundarams_sieve wc strlen_uft8

all:$(TARGETS)

$(TARGETS): %: %.c
	$(CC) $< -o $@



clean: 
	rm -f $(TARGETS)
	rm -f *.exe
	rm -f *.o

