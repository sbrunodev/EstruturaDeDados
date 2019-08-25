#include <conio2.h>
#include <stdlib.h>
#include <stdio.h>
#include "PilhaInt.h"

int main ()
{
	int TL=0;
	int vetNumero [5];	
	TpPilha Pilha;
	Inicializar (Pilha);
	
	while (TL<5)
	{
		printf (" %d - Numero: ",TL+1);
		scanf ("%d",&vetNumero[TL]);
		
		TL++;	
	}
	
	while (TL>=0)
	{
		Inserir(Pilha,vetNumero[TL]);
		TL--;	
	}
	
	TL=0;
	printf ("Vetor: ");
	while (TL<5)
	{
		printf (" %d ",vetNumero[TL]);		
		TL++;	
	}
	
	printf ("\nPilha");
	ExibePilha(Pilha);
	
	getch ();
	
}
