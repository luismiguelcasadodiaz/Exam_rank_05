#ifndef MATRIX_H
# define MATRIX_H
#include <stdbool.h>

typedef struct matrix
{
	int		cols;
	int		rows;
	char	*data;
}	Matrix;

Matrix	*M_create(int cols, int rows, char *seed);
void	M_free(Matrix *m);
void	M_print(Matrix *m);
char	M_get(Matrix *m, int col, int row);
void	M_set(Matrix *m, int col, int row, char c);
void	M_seed(Matrix *m, char *seed);
bool	M_inside(Matrix *m, int col, int row);
int		M_neighbours(Matrix *m, int col, int row);
Matrix *M_generation(Matrix *m);
void	M_copy(Matrix *origen, Matrix *destino);
void	msg(char *txt);
#endif
