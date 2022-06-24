#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE *ptrArq;

	ptrArq = fopen ("output1.exe", "rb");

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


	fread(testePersonalizado, sizeof(testePersonalizado), 1, ptrArq);

	fclose(ptrArq);

	//system("pause");

	FILE *ptrArq2;

	ptrArq2 = fopen ("outputInt1.txt", "w");

	if(ptrArq2 != NULL)
		printf ("success open\n");
	else
	{
		printf ("error open\n");
		system ("pause");
		exit (1);
	}
	
	for (int i = 0; i < sizeof(testePersonalizado); i++)
	{
		fprintf(ptrArq2, "%d\n", (testePersonalizado[i] - '0'));
	}

	fclose(ptrArq2);

	system("pause");

	return 0;
}
