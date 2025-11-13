#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "matrix.h"


void read_seed(char * seed, size_t max_bytes)
{
	size_t bytes_read;
	bytes_read = read(STDIN_FILENO, seed, max_bytes);
	if (bytes_read > 0)
	{
		seed[bytes_read] = '\0';
		size_t len = strlen(seed);
		if ( ( len > 0 ) && ( seed[len - 1] == '\n' ) )
			seed[len - 1] = '\0';
	} else if (bytes_read == 0)
	{
		msg("No seed available (EOF)");
	} else 
	{
		msg("Error reading stdin");
		exit (3);
	}
}
int main( int argc, char ** argv)
{
	Matrix *m;
	Matrix *new;
	char seed[1024];
	int i;
	if (argc != 4)
	{
		msg("Usage ./life width height iterations\n");
		return (0);
	}
	read_seed(seed, sizeof(seed));
	m = M_create(atoi(argv[1]), atoi(argv[2]), seed);
	i = 0;
	while (m != NULL && i <= atoi(argv[3]) )
	{
		msg("iteration\n");
		M_print(m);
		new = M_generation(m);
		M_free(m);
		m = new;
		i++;
	}
	M_free(m);
	return (0);
}

