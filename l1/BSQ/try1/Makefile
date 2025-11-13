all: bsq

bsq: bsq.c matrix.c file.c
	clang -g -Werror -Wextra -Wall file.c matrix.c bsq.c -o $@

clean:
	rm bsq

re: clean bsq
