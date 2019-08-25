#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>


bool maiusculo (char nomeArq1[50], char nomeArq2[50])
{
	char linhaArq1[50],linhaArq2[50];
	FILE *Arq1 = fopen (nomeArq1,"r");
	FILE *Arq2 = fopen (nomeArq2,"r");
	
	
	if ( Arq1 == NULL && Arq2 == NULL)
		printf ("\n Arquivo nao Aberto ! \n ");
	else
	{
		while(!feof(Arq1))
		{
			if (strcmp(fgets(linhaArq1,50,Arq1),fgets(linhaArq2,50,Arq2))==0)
			{
				
			}
			else
				return false;
		}
			return true;
	}

	
	fclose(Arq1);
	fclose(Arq2);
}

int main ()
{
	if (maiusculo ("Arquivo1.txt","Arquivo2.txt")==true)
		printf ("Os arquivos sao identicos ! ");
	else
		printf ("Os arquivo sao diferentes ! ");
			
}
