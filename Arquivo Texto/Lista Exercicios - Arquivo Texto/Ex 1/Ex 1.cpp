#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>


void maiusculo (char nomeArq[50])
{
	char caracter;
	FILE *Arq = fopen (nomeArq,"r");
	FILE *M = fopen ("Maiusculo.txt","w");
	
	if ( Arq == NULL)
		printf ("\n Arquivo nao Aberto ! \n ");
	else
	{
		caracter = getc(Arq);
		while(!feof(Arq))
		{
			
			caracter = toupper (caracter);
			
			printf ("%c",caracter);
			fputc (caracter, M); // O que, Onde 
			
			caracter = getc(Arq);
		}
	}
	
	fclose(Arq);
	fclose(M);
}

int main ()
{
	maiusculo ("Bruno.txt");	
}
