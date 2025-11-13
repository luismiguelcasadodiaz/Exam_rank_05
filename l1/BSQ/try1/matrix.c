#include "matrix.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
M		*M_create(int c, int r)
{
	M *m;
	m=(M*)malloc(sizeof(M));
	if (m == NULL)
	{
		fprintf(stdout, "malloc fail matrix creation\n");
		return (NULL);
	}
	m->d=(char *)malloc(c * r * sizeof(char) );
	if (m->d == NULL)
	{
		fprintf(stdout, "malloc fail data creation\n");
		free(m);
		return (NULL);
	}
	m->DP=(int *)malloc(c * r * sizeof(int) );	
	m->c = c;
	m->r = r;
	return (m);
}
void M_free(M *m)
{
	free(m->d);
	free(m);
}
void M_init(M *m)
{
	int x;
	int y;
	y = 0;
	while (y < m->r)
	{
		x = 0;
		while (x < m->c)
		{
			m->d[y * m->c + x++ ]= m->empt;
			m->DP[y * m->c + x++ ]= 0;
		}
		y++;
	}
}


void	M_print(M *m)
{
	int x;
	int y;
	char txt[2];
	y = 0;
	while (y < m->r)
	{
		x = 0;
		while (x < m->c)
		{
			//txt[0] =*m->d[y * m->c + x++];
			txt[0] = M_get(m, x++, y);
			txt[1] = '\0';
			fputs(txt, stdout);
			//fputs(&m->d[y * m->c + x++], stdout);
		}
		fputs("\n",stdout);
		y++;
	}
	y = 0;
	while (y < m->r)
	{
		x = 0;
		while (x < m->c)
		{
			
			txt[0] = '0' + M_get_DP(m, x++, y);
			txt[1] = '\0';
			fputs(txt, stdout);
			
		}
		fputs("\n",stdout);
		y++;
	}	
}
void	M_set(M *m, int c, int r, char d)
{
	m->d[r * m->c + c ]= d;
}
char	M_get(M *m, int c, int r)
{
	return (m->d[r * m->c + c ]);
}

void	M_set_DP(M *m, int c, int r, int d)
{
	m->DP[r * m->c + c ]= d;
}
int		M_get_DP(M *m, int c, int r)
{
	return (m->DP[r * m->c + c ]);
}

M		*M_read_from_file(char *filename)
{
	M 		*m;
	int		rows;
	char	empt;
	char	obst;
	char	fill;
	fprintf(stdout,"%s\n",filename);
	FILE *fd = fopen(filename,"r");
	if (fd == NULL) {
		fprintf(stderr, "Problemas en la apertura de %s .\n", filename);
		return (NULL);
	}
	if ( (fscanf(fd, " %d %c %c %c", &rows, &empt, &obst, &fill)) != 4)
	{
		fprintf(stderr, "map error1\n");
		return (NULL);
	}

	//while ( (c=fgetc(fd)) != '\n' && c != EOF);  //vacio el buffer
	char 	*line1=NULL;
	char 	*line=NULL;
	size_t	line_len=0;
	int	read_bytes;
	read_bytes = getline(&line1, &line_len, fd);//vacio el buffer
	free(line1);
	read_bytes = getline(&line, &line_len, fd);
	if (read_bytes == -1)
	{
		fprintf(stderr, "map error2\n");
		free(line);
		return (NULL);
	}
	int idx = 0;
	while (line[idx] != '\0' && line[idx++] != '\n');
	m = M_create(--idx, rows);
	m->empt = empt;
	m->obst = obst;
	m->fill = fill;
	M_init(m);
	
	idx = 0;
	rows = 0;
	while (idx < m->c)
	{
		if ( (line[idx] == m->empt) || (line[idx] == m->obst) )
		{
			M_set(m, idx, rows, line[idx]);
		} else if ( line[idx] != '\n' ) {
			M_free(m);
			free(line);
			fprintf(stderr, "map error3\n");
			return (NULL);
		}
		idx++;
	}
	rows = 1;
	while ( (( read_bytes = getline(&line, &line_len, fd) ) != -1  ) && ( rows < m->r ) )
	{
		idx = 0;
		while (line[idx] != '\0' && line[idx++] != '\n');
		if (--idx != (m->c) )
		{
			fprintf(stderr, "map error4\n");
			free(line);
			M_free(m);
			return(NULL);
		}
		idx = 0;
		while (idx < m->c)
		{
			if ( (line[idx] == m->empt) || (line[idx] == m->obst) )
			{
				M_set(m, idx, rows, line[idx]);
			} else if ( line[idx] != '\n' ) {
				M_free(m);
				free(line);
				fprintf(stderr, "map error5\n");
				return (NULL);
			}
			idx++;
		}
		rows++;
		//free(line);
	}
	if (rows != m->r)
	{
		fprintf(stderr, "map error6\n");
		free(line);
		M_free(m);
		return(NULL);
	}
	fclose(fd);
	//free(line);
	return (m);
}
void	M_bsq(M *m)
{
	int x;
	int y;
	int max = 0;
	int aux;
	y = 0;
	while (y < m->r)
	{
		x = 0;
		while (x < m->c)
		{
			if ( M_get(m, x, y) == m->empt)
			{
				aux = 1 + M_min(m, x, y);
				if (aux > max) {max = aux;}
				M_set_DP(m, x, y, aux);
			} else {
				M_set_DP(m, x, y, 0);
			}
			x++;
			
		}
		y++;
	}
	M_br_coor_bsq(m, max, &x, &y);
	int width= max;
	int heigth = max;
	int bsq_y = y;
	int bsq_x ;
	while (heigth > 0)
	{
		bsq_x = x;
		width = max;
		while (width > 0)
		{
			M_set(m, bsq_x, bsq_y, m->fill);
			bsq_x--;
			width--;
		}
		heigth--;
		bsq_y--;
	}

}

int	M_min(M *m, int c, int r)
{
	int lrc;
	int l;
	int u;
	
	if ( ( 0 <= (c - 1) ) && ( 0 <= (r - 1) ) )
	{
		lrc = M_get_DP(m, c - 1 , r - 1);
	} else {
		lrc = 0;
	}
	if ( 0 <= (c - 1) )
	{
		l = M_get_DP(m, c - 1, r);
	} else {
		l = 0;
	}
	if ( 0 <= (r - 1) )
	{
		u = M_get_DP(m, c, r - 1);
	} else {
		u = 0;
	}
	return ( (lrc < l) ? ( ( lrc < u) ? lrc : u ): (l < u?  l:u) );
}
void M_br_coor_bsq(M *m, int max, int *x, int *y)
{

	*y = 0;
	while (*y < m->r)
	{
		*x = 0;
		while (*x < m->c)
		{
			if ( M_get_DP(m, *x, *y) == max)
			{
				return;
			}
			(*x)++;
		}
		(*y)++;
	}	
}