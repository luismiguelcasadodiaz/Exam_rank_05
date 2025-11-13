#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <error.h>

void msg(char *txt)
{
	int i = 0;
	while (txt[i] != '\0')
		putchar(txt[i++]);
}

Matrix *M_create(int cols, int rows, char *seed){
	Matrix *m;

	m = (Matrix *)malloc(sizeof(Matrix));
	if (m == NULL)
	{
		return (NULL);
	}
	m->data = (char *) malloc(cols * rows * sizeof(char));
	if (m->data == NULL)
	{
		free(m);
		return (NULL);
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
	return (m);
}
void M_print(Matrix *m)
{
	int rows = 0;
	int cols = 0;

	while (rows < m->rows)
	{
		cols = 0;
		while (cols < m->cols)
			putchar(M_get(m, cols++, rows));
		rows++;
		putchar('\n');
	}
}
char M_get(Matrix *m, int col, int row)
{
	if ( (col < m->cols) && (row < m->rows) )
	{
		return (m->data[m->cols * row + col]);
	}
	fprintf(stderr,"Index out of range:col=%d, row=%d \n", col, row);
	exit (1);
}
void M_set(Matrix *m, int col, int row, char c)
{
	if ( (col < m->cols) && (row < m->rows) )
	{
		m->data[m->cols * row + col]= c;
		return;
	}
	fprintf(stderr, "Index out of range:col=%d, row=%d \n", col, row);
	exit (2);
}
void M_seed(Matrix *m, char *seed)
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
		} else if ( seed[idx] == 'w') // up
		{
			if ( row > 0 ) { row -=1 ; }
		} else if ( seed[idx] == 'a') // left
		{
			if ( col > 0 ) { col -=1 ; }
		} else if ( seed[idx] == 's') // bottom
		{
			if ( row < m->rows - 1 ) { row +=1 ; }
		} else if ( seed[idx] == 'd') // right
		{
			if ( col < m->cols - 1 ) { col +=1 ; }
		} else 
		{
			msg("Wrong seed command");
			exit(4);
		}
		if (pen) {M_set(m, col, row, '0');}
		idx++;

	}
}

bool	M_inside(Matrix *m, int col, int row)
{
	return ( ( ( 0 <= col ) && ( col < m->cols ) ) && ( ( 0 <= row )  && ( row < m->rows ) ) ) ;
}
int	M_neighbours(Matrix *m, int col, int row)
{
	int n = 0;

	n += ( M_inside(m, col - 1, row - 1) && ( M_get(m, col - 1, row - 1) == '0' ) );
	n += ( M_inside(m, col    , row - 1) && ( M_get(m, col    , row - 1) == '0' ) );
	n += ( M_inside(m, col + 1, row - 1) && ( M_get(m, col + 1, row - 1) == '0' ) );
	n += ( M_inside(m, col - 1, row    ) && ( M_get(m, col - 1, row    ) == '0' ) );
	n += ( M_inside(m, col + 1, row    ) && ( M_get(m, col + 1, row    ) == '0' ) );
	n += ( M_inside(m, col - 1, row + 1) && ( M_get(m, col - 1, row + 1) == '0' ) );
	n += ( M_inside(m, col    , row + 1) && ( M_get(m, col    , row + 1) == '0' ) );
	n += ( M_inside(m, col + 1, row + 1) && ( M_get(m, col + 1, row + 1) == '0' ) );
	return n;
}
Matrix *M_generation(Matrix *m)
{
	int row = 0;
	int col = 0;
	int neighbours;
	Matrix *new = M_create(m->cols, m->rows, "aa");

	while (row < m->rows)
	{
		col = 0;
		while (col < m->cols)
		{
			neighbours = M_neighbours(m, col, row);
			if ( M_get(m, col, row) == '0' ) // it is alive
			{
				if ( ( neighbours < 2) || ( 3 < neighbours ) )
				{
					M_set(new, col, row, ' ');
				}
				else
				{
					M_set(new, col, row, '0');
				}
			} else if (neighbours == 3) // is not alive
			{
				M_set(new, col, row, '0');
			}
			col++;

		}
		row++;
	}
	return (new);
}
void M_free(Matrix *m)
{
	free(m->data);
	free(m);
}
void	M_copy(Matrix *origen, Matrix *destino)
{
	int rows = 0;
	int cols = 0;

	while (rows < origen->rows)
	{
		cols = 0;
		while (cols < origen->cols)
		{
			M_set(destino, cols, rows, M_get(origen, cols, rows));
			cols++;
		}
		rows++;
	}
}
