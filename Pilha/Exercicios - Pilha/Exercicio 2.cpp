#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include "Pilha.h"

char Menu ()
{
	clrscr();
	printf ("MENU\\ \n\n");	
	
	printf ("[A] - Adicionar Elem. a Pilha  \n");
	printf ("[S] - Excluir Elem. a Pilha 2 \n\n");
	
	printf ("[ESC] - Sair ");
	return toupper(getche());	
}

void adicElem (TpPilha &Pilha)
{
	clrscr();
	char Elem;
	
	printf ("MENU\\ADD PILHA  \n\n");
	if (PilhaCheia(Pilha.Topo))
		printf ("Pilha Cheia ! \n");
	else
		{
			printf ("Elem: ");
			Elem = getche();
			Inserir (Pilha,Elem);
			
			printf ("\n Insercao Realizada ! ");
		}
		
		ExibePilha(Pilha);
		getch ();
}


void excluiElem (TpPilha &Pilha)
{
	
	clrscr ();
	char Elem='b';
		
	printf ("MENU\\EXCLUI ELEM \n");
	TpPilha Aux;Inicializar(Aux);
	printf ("Elem: ");
	scanf("%c",&Elem);
	
	
	while (!PilhaVazia(Pilha.Topo)) // Roda todos os elementos da pilha ! 
	{
		if (RetornaElem(Pilha)==Elem) // Pergunta se o elemento é igual o que está procurando caso for
		{
			Retirar (Pilha); // Ele retira ...
		}
		else
		{
			Inserir (Aux,Retirar(Pilha)); // E caso não for ele insere no Aux		
		}
			
		
	}	
	
	while (!PilhaVazia(Aux.Topo)) 
	{
		Inserir (Pilha,Retirar(Aux));
	}

	printf ("Elementos Restantes: \n");	
	ExibePilha(Pilha);
	getch ();
	
}

void Executa ()
{
	TpPilha Pilha;
	Inicializar(Pilha);
	char Op;
	
	do {
		Op=Menu();
		
		switch (Op)
		{
			case 'A': adicElem (Pilha);break;
			case 'S' : excluiElem(Pilha);break;
		}
		
	}while(Op!=27);
		
	
	
}


int main ()
{
	Executa ();
	
}
