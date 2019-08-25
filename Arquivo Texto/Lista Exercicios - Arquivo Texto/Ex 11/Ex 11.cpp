#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>


void enumeraPag (char nomeArq1[50])
{
	
	FILE *Arq1 = fopen (nomeArq1,"r");
	int i=0;
	char linha[99];

	if (Arq1==NULL)
		printf ("Arquivo nao Aberto ! \n");
	else
	{
		fgets(linha,99,Arq1);
		
		while (!feof(Arq1))
		{
			printf ("%d - %s \n",i,linha);
			i++;
			fgets(linha,99,Arq1);
		}	
	}
	getch ();
	
	fclose(Arq1);

}

int main ()
{
	enumeraPag("Alfabeto.txt");
			
}
