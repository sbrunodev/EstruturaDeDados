#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>


void priLetraMaiusculo (char nomeArq1[50])
{
	char linha[50];
	FILE *Arq1 = fopen (nomeArq1,"r");
	FILE *Arq2 = fopen ("1LetraMaiusculo.txt","w");
	int i;
	
	if ( Arq1 == NULL )
		printf ("\n Arquivo nao Aberto ! \n ");
	else
	{
		fgets (linha,50,Arq1);
		
		//linha[i]=toupper(linha[i]);
		
		while(!feof(Arq1))
		{
			
			for (i=0;i<50;i++)
			{
				if (linha[i]==' ')
					linha[i+1]=toupper(linha[i+1]);
			}
			fputs(linha, Arq2);
			
			fgets (linha,50,Arq1);	
		
			
		}

	}

	
	fclose(Arq1);
	fclose(Arq2);

}

int main ()
{
	priLetraMaiusculo ("Bruno.txt");
			
}
