#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include "Pilha.h"

char Menu ()
{
	clrscr();
	printf ("MENU\\ \n\n");	
	printf ("[A] - Adicionar Elem. a Pilha 1 \n");
	printf ("[S] - Adicionar Elem. a Pilha 2 \n");
	printf ("[D] - Concatenar Pilhas \n\n ");
	printf ("[ESC] - Sair ");
	return toupper(getche());	
}

void adicPilha1(TpPilha &P1)
{
	clrscr();
	char Elem;
	
	printf ("MENU/ADD PILHA 1 \n\n");
	if (PilhaCheia(P1.Topo))
		printf ("Pilha Cheia ! \n");
	else
		{
			printf ("Elem: ");
			Elem = getche();
			Inserir (P1,Elem);
			
			printf ("\n Insercao Realizada ! ");
		}
		
		getch ();
}

void adicPilha2(TpPilha &P2)
{
	clrscr();
	char Elem;
	printf ("MENU\\ADD PILHA 2 \n\n");
	if (PilhaCheia(P2.Topo))
		printf ("Pilha Cheia ! \n");
	else
		{
			printf ("Elem: ");
			Elem = getche();
			Inserir (P2,Elem);
			
			printf ("\n Insercao Realizada ! ");
		}
		
		getch ();
}

void Concatena (TpPilha P1, TpPilha P2)
{
	TpPilha Aux;
	Inicializar(Aux);
	clrscr();
	printf ("MENU\\CONCATENA \n");

	
	while (!PilhaVazia(P2.Topo))
	{
		if (PilhaCheia(Aux.Topo))
			printf ("A Pilha Aux esta cheia ! ");
			
		else
			Inserir (Aux,Retirar(P2));

	}
	
	while (!PilhaVazia(Aux.Topo))
	{
		if (PilhaCheia(P1.Topo))
			printf ("A Pilha 1 esta Cheia");
		
		else
			Inserir (P1,Retirar(Aux));
	}
	
	
	ExibePilha(P1);
	
	getch ();
	
}

void Executa ()
{
	TpPilha P1, P2;
	Inicializar(P1),Inicializar(P2);
	char Op;

	do{
		Op=Menu();
		
		switch (Op)
		{
			case 'A': adicPilha1(P1);break; 
			case 'S': adicPilha2(P2);break;
			case 'D': Concatena (P1,P2);break;
		}
		
		
	}while (Op!=27);
}


int main ()
{
	Executa();
}
