#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

void leArq (char nomeArq[50])
{
	
	char caracter;
	
	FILE *Arq = fopen (nomeArq,"r");
	if (Arq == NULL)
		printf ("\n Arquivo nao Aberto ! \n");
	else
	{
		caracter = fgetc (Arq);
		while (!feof(Arq))
		{
			printf ("%c",caracter);
			
			caracter = fgetc (Arq);
			
		}
		printf ("\n\n Final do Arquivo \n");
	}
	getch ();
    fclose (Arq);
}

void leArqS(char nomeArq[50])
{
	char texto[100];
	FILE* Arq = fopen (nomeArq,"r");
	if (Arq==NULL)
		printf ("\n Arquivo nao aberto ! \n");
	else
		while (fgets(texto,100,Arq)!=NULL)
			printf ("\n %s",texto);

	printf ("\n\n Fim do Arquivo \n");	
	getch ();
	fclose(Arq);
	
}

void gravaArq(char nomeArq[50])
{
	char caracter;

	FILE *Arq = fopen (nomeArq,"a");
	
	fputc (caracter,Arq);	
	caracter = getche();
	while (caracter!=27)
	{
		if (caracter == 13)
		{
			fputc ('\n',Arq);
			printf ("\n");
		}
		else
			fputc(caracter,Arq);
			
		caracter = getche();	
	}
	getch ();
	fclose(Arq);
	
}




int main (void)
{
	gravaArq("Bruno.txt");
	//leArq("Bruno.txt");
	//leArqS("Bruno.txt");
	
}
