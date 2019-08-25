#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>


int vogal (char nomeArq1[50])
{
	char linha[99];
	FILE *Arq1 = fopen (nomeArq1,"r");
	int i=0,vogais=0;
	
	
	if ( Arq1 == NULL )
		printf ("\n Arquivo nao Aberto ! \n ");
	
	else
	{
		fgets(linha,99,Arq1);	
		while(!feof(Arq1))
		{
			printf ("%s",linha);
			
			for (i=0;i<99;i++)
			{
				if (linha[i]==' ')
				{
					if(linha [i+1] == 'a' || linha [i+1] == 'A' || linha [i+1] == 'e' || linha [i+1] == 'E' || linha [i+1] == 'i' || linha [i+1] == 'I' ||
					linha [i+1] == 'o' || linha [i+1] == 'O' || linha [i+1] == 'u' || linha [i+1] == 'U' )
					{
						vogais++;
					}    
				}	
			}
			
			fgets(linha,99,Arq1);
		}
			
	}
	
	return vogais;
	fclose(Arq1);

}

int main ()
{
	printf ("Palavras que iniciam com Vogais: %d",vogal("Texto.txt"));
			
}
