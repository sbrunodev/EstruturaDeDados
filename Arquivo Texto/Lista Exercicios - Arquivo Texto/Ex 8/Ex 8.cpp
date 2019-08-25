#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void descriptografe ()
{
	FILE *Arq1=fopen ("C:\\Users\\Bruno\\Desktop\\Faculdade\\Ed l\\Arquivo Texto\\Lista Exercicios - Arquivo Texto\\Ex 7\\Codifica.txt","r");
	FILE *Desc=fopen("Descodifica.txt","w");
	char linha[99];
	int i;
	
	if (Arq1==NULL)
		printf ("\n Arquivo nao aberto ! ");
	else
	{
		fgets (linha,99,Arq1);
		while (!feof(Arq1))
		{
			
			for (i=0;i<99;i++)
			{
				if (linha [i]=='#')
					linha[i]='a';
				if (linha [i]=='@')
					linha[i]='e';
				if (linha [i]=='*')
					linha[i]='e';
				
			}
			fputs (linha,Desc);
			
			fgets (linha,99,Arq1);
		}
		
		
	}
	
	fclose(Arq1);
	fclose(Desc);
	
	
	
}



int main ()
{
	descriptografe ();
	
}
