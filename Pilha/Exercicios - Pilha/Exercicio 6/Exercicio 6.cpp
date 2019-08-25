#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "Pilha.h"

int inverteArq (char nomeArq[15])
{
	TpPilha Pilha;
	Inicializar (Pilha);
	char caractere;
	FILE *Arq = fopen (nomeArq,"r");
	
	caractere = getc (Arq);
	while(!feof(Arq)) 
	{
		if (PilhaCheia(Pilha.Topo))
		{
			printf ("Pilha Cheia ! \n");
			return 0;
		}
		else
		{
			Inserir (Pilha,caractere);	
			
		}
		
		caractere = getc (Arq);
	}
	
	FILE *Inverte = fopen ("ArqInvertido.txt","w");
	
	while (!PilhaVazia(Pilha.Topo))
	{
		fputc (Retirar(Pilha),Inverte);
	}
	
	return 1;
	
	
}


int main()
{
	if (inverteArq ("Arquivo.txt")==1)
		printf ("Arquivo invertido");
	else
		printf ("ERROR");
		
	getch ();
	
	
	
}
