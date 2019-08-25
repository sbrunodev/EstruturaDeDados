#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alteraVogais (char nomeArq[50])
{
	FILE *Arq = fopen (nomeArq,"r");
	FILE *Alterado = fopen ("Alterado.txt","w");
	char c;
	int i;

	
	if (Arq==NULL)
		printf ("\n Arquivo nao aberto ! ");
	else
	{
	
		c = fgetc(Arq);
		while (!feof(Arq))
		{
			if (c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U' )
			{
				c ='@';
			}
			fputc (c,Alterado);
			c = fgetc(Arq);
		}
		printf ("Vogais Substituidas ! ");
	}	
	fclose (Alterado);
	fclose(Arq);
}

int main ()
{
	alteraVogais("Arquivo.txt");
}
