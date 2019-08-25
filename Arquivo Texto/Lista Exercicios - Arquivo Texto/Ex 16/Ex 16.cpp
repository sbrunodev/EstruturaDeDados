#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

bool contaParenteses (char nomeArq[30])
{
	FILE *Arq = fopen (nomeArq,"r");
	char caracter, compara[99];
	int parenAbre=0, parenFecha=0;
	
	
	caracter = fgetc(Arq);
	while (!feof(Arq))
	{
		if (caracter=='(')
			parenAbre++;
				
		if (caracter==')')
			parenFecha++;
			
		if (parenFecha>parenAbre)
			return false;
	
	}
	fclose(Arq);
	
}


int main ()
{
	if (contaParenteses ("Arquivo.txt")==true)
		printf ("Para cada aberto tem um fechado ! ");
	else
		printf (" Parenteses Fechado ) sem nenhum aberto ! ");
		
}
