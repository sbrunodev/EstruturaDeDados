#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

int Palindromo ()
{
	TpPilha Pilha;
	Inicializar(Pilha);
	int i;
	
	char Palavra [10];
	
	printf ("Informe a Palavra: ");
	fflush(stdin);
	gets(Palavra);
	

	for (i=0;i<strlen(Palavra);i++)
	{
		
		if (!PilhaCheia(Pilha.Topo))
		{
			Inserir(Pilha,Palavra[i]);
		}
		else
		{
			printf("Erro Pilha Cheia ! \n\n");
		
		}
	}


	
	i=0;
	while (!PilhaVazia(Pilha.Topo))
	{
		if (Retirar(Pilha)!=Palavra[i])
			return 0;
			
		i++;
	}
	
	return 1;
}


int main ()
{

	
	if (Palindromo()==1)
		printf ("\n\n Esta palavra e Palindromo !");
	else
		printf ("\n\n Esta palavra nao e Palindromo");

	getch ();
}

