#ifndef MATRIX_HH
#define MATRIX_HH

typedef struct
{
	char	empt;
	char	obst;
	char	fill;
	int 	c;
	int 	r;
	char 	*d;
	int		*DP;
}	M;

M		*M_create(int c, int r);
void	M_free(M *m);
void	M_init(M *m);
void	M_print(M *m);
void	M_set(M *m, int c, int r, char d);
char	M_get(M *m, int c, int r);
void	M_set_DP(M *m, int c, int r, int d);
int		M_get_DP(M *m, int c, int r);
M		*M_read_from_file(char *filename);
void	M_bsq(M *m);
int		M_min(M *m, int c, int r);
void 	M_br_coor_bsq(M *m, int max, int *x, int *y);


#endif
