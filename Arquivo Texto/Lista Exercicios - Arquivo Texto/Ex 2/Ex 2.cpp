#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>


void maiusculo (char nomeArq[50])
{
	char caracter;
	FILE *Arq = fopen (nomeArq,"r");
	int i=0;
	
	if ( Arq == NULL)
		printf ("\n Arquivo nao Aberto ! \n ");
	else
	{
		caracter = getc(Arq);
		while(!feof(Arq))
		{
			i++;//Conta
			printf ("%c",caracter);//Exibe
			caracter = getc(Arq);
		}
		printf ("\nTotal: %d",i);
	}
	
	
	fclose(Arq);
}

int main ()
{
	maiusculo ("Bruno.txt");	
}

