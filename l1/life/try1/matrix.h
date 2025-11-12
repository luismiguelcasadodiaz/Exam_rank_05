#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
	int cols;
	int rows;
	char *data;
} Matrix;

Matrix * M_create(int cols, int rows, char * seed);
void M_print(Matrix * m);
char M_get(Matrix * m, int col, int row);
void M_set(Matrix * m, int col, int row, char c);
void M_seed(Matrix * m, char * seed);

#endif
