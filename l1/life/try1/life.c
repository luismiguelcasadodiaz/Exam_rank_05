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
		printf("No seed available (EOF)");
	} else 
	{
		perror("Error reading stdin");
		exit (3);
	}
}
int main( int argc, char ** argv)
{
	Matrix *m;
	char seed[1024];
	int i;
	if (argc != 4)
	{
		printf("Usage ./life width height iterations\n");
		return (0);
	}
	read_seed(seed, sizeof(seed));
	m = M_create(atoi(argv[1]), atoi(argv[2]), seed);
	i = 1;
	while (m != NULL && i < atoi(argv[3]) )
	{
		M_print(m);
		i++;
		printf("%s\n",seed);
	}
	return (0);
}

