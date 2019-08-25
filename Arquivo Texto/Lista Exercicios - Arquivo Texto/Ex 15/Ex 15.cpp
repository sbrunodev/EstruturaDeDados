#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substitui (char nomeArq[30],char letra, char caractere)
{
	FILE *Arq = fopen (nomeArq,"r");
	FILE *Alterado = fopen ("Alterado.txt","w");
	char c;
	if (Arq==NULL)
		printf ("\n Arquivo nao aberto ! ");
	else
	{
	
		c = fgetc(Arq);
		while (!feof(Arq))
		{
			if ( c==letra )
			{
				c=caractere;
			}
			if ( c==13)
			{
				c='\n';
			}
			fputc (c,Alterado);
			c = fgetc(Arq);
		}
	}	
	fclose (Alterado);
	fclose(Arq);
}

int main ()
{
	char nomeArq [30], letra, caractere;
	printf ("Nome do Arquivo : ");
	fflush(stdin);
	gets(nomeArq);
	
	printf ("Informe a Letra: ");
	scanf ("%c",&letra);
	
	printf ("Informe o Caractere: ");
	fflush(stdin);
	scanf ("%c",&caractere);
	
	substitui (nomeArq,letra,caractere);
}
