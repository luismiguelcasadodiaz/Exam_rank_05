#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <error.h>

Matrix * M_create(int cols, int rows, char *seed){
	Matrix *m;
	m = (Matrix *)malloc(sizeof(Matrix));
	if (m == NULL)
	{
		return NULL;
	}
	m->data = (char *) malloc(cols * rows * sizeof(char));
	if (m->data == NULL)
	{
		free(m);
		return NULL;
	}
	m->cols = cols;
	m->rows = rows;
	rows = 0;
	while (rows < m->rows)
	{
		cols = 0;
		while (cols < m->cols)
			M_set(m, cols++, rows, ' ');
		rows++;
	}
	M_seed(m, seed);
	return m;
}
void M_print(Matrix * m)
{
	int rows = 0;
	int cols = 0;
	while (rows < m->rows)
	{
		cols = 0;
		while (cols < m->cols)
			printf("%c",M_get(m, cols++, rows));
		rows++;
		printf("\n");
	}
}
char M_get(Matrix * m, int col, int row)
{
	if ( (col < m->cols) && (row < m->rows) )
	{
		return m->data[m->cols * row + col];
	}
	perror("Index out of range");
	exit (1);
}
void M_set(Matrix * m, int col, int row, char c)
{
	if ( (col < m->cols) && (row < m->rows) )
	{
		m->data[m->cols * row + col]= c;
		return;
	}
	perror("Index out of range");
	exit (2);
}
void M_seed(Matrix * m, char * seed)
{
	int col = 0;
	int row = 0;
	int idx = 0;
	int pen = 0;
	while (seed[idx])
	{
		if (seed[idx] == 'x' )
		{
			pen = ( pen ? 0 : 1);
		} else if ( ( seed[idx] == 'w') && ( row > 0 ) ) // up
		{
			row -=1 ;
		} else if ( ( seed[idx] == 'a') && () ) // left
		{
		} else if ( ( seed[idx] == 's') && ( row < m->rows) ) // bottom
		{
			row +=1 ;
		} else if ( ( seed[idx] == 'd') && () ) // right
		{
		} else 
		{
			perror("Wrong seed command");
			exit(4);
		}

	}
}
