#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contLetra (char nomeArq[50])
{
	FILE *Arq = fopen (nomeArq,"r");
	char linha[99];
	int i,lin=0,y=0,x,contl=0;
	
	if (Arq==NULL)
		printf ("\n Arquivo nao aberto ! ");
	else
	{
		char letra;
		printf ("Informe a Letra :\n ");
		scanf ("%c",&letra);
		fgets(linha,99,Arq);
		while (!feof(Arq))
		{
			printf ("%d - %s",lin,linha);
			x=0;
			for (i=0;i<99;i++)
			{
				if (linha[i]==letra)
				{
					x++;
				}
			}
			
			if (x>y)
			{
				y=x;
				contl=lin;
			}
			lin++;
			fgets(linha,99,Arq);
		}
		
		return contl;
		
	}	
	
	fclose(Arq);
}

int main ()
{
	printf ("\n\t Linha: %d",contLetra("Arquivo.txt"));	
}
