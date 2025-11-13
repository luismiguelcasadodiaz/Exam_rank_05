#include "file.h"
#include "matrix.h"
#include <stdio.h>
#include <unistd.h>
int	main (int argc, char **argv)
{
	M *m;
	char filename[FILE_MAX_LENGTH];
	if (argc == 1)
	{
		F_get_filename(filename) ;
		m=M_read_from_file(filename);
		if ( m != NULL )
		{
			M_bsq(m);
			M_print(m);
			M_free(m);
			return(0);
		}
	} else if (argc == 2)
	{
		m=M_read_from_file(argv[1]);
		if ( m != NULL )
		{
			M_bsq(m);
			M_print(m);
			M_free(m);
			return(0);
		}
	} else
	{
		int idx=1;
		while (idx < argc)
		{
			m=M_read_from_file(argv[idx]);
			if ( m != NULL )
			{
				M_bsq(m);
				M_print(m);
				M_free(m);
			}
			idx++;
		}
	}
	return (0);
}
