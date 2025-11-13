#include "file.h"

void F_get_filename(char *filename)
{
	int len;
	fprintf(stdout, "Introduce el nombre del fichero: \n");
	len = fscanf(stdin, "%255s",filename);
	if (len == 1)
	{
		int c;
		while ( (c=fgetc(stdin)) != '\n' && c != EOF);
	} else if (len == EOF)
	{
		fprintf(stdout, "Fin de la entrada alcanzado (EOF) \n");
		filename[0]='\0';
	} else 
	{
		fprintf(stdout, "Error en el formato de entrada \n");
		filename[0]='\0';
	}

}
