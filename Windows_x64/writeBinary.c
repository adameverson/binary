#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

	FILE *ptrArq;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	ptrArq = fopen ("outputInt1.txt", "r");

	fseek(ptrArq, 0, SEEK_END); // seek to end of file
	char testePersonalizado [ftell(ptrArq)];
	fseek(ptrArq, 0, SEEK_SET); // seek back to beginning of file
	// proceed with allocating memory and reading the file

	if(ptrArq != NULL)
		printf ("success open\n");
	else
	{
		printf ("error open\n");
		system ("pause");
		exit (1);
	}

	FILE *ptrArq2;

	ptrArq2 = fopen ("outputChar1.exe", "wb");

	if(ptrArq2 != NULL)
		printf ("success open\n");
	else
	{
		printf ("error open\n");
		system ("pause");
		exit (1);
	}

	int i;
	char c [1]; 

	while ((read = getline(&line, &len, ptrArq)) != -1)
	{
		i = atoi(line);
		//printf("%d", i);
		c[0] = (i + '0');
		//printf("%c", c[0]);
		fwrite(c, sizeof(char), 1, ptrArq2);
	}

	fclose(ptrArq2);

	fclose(ptrArq);

	if(line)
		free(line);

	system("pause");

	return 0;
}
