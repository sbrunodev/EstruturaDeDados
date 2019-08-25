#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void codifica (char nomeArq [50])
{
	FILE *Arq1=fopen (nomeArq,"r");
	FILE *Cod=fopen("Codifica.txt","w");
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
				if (linha [i]=='a')
					linha[i]='#';
				if (linha [i]=='e')
					linha[i]='@';
				if (linha [i]=='o')
					linha[i]='*';
				
			}
			fputs (linha,Cod);
			
			fgets (linha,99,Arq1);
		}
		
		
	}
	
	fclose(Arq1);
	fclose(Cod);
	
	
	
}



int main ()
{
	codifica ("Arquivo.txt");
	
}
