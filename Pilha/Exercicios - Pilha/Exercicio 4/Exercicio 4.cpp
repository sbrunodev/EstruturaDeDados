#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <time.h>
#include "Pilha.h"

int main ()
{
	int i=0,Rodadas,NumVetor=0,x=0,Vet=0,y=0,Cor=0;
	
	printf ("Informe o numero de Pilhas: ");
	scanf ("%d",&NumVetor);
		
	//TpPilha Pilha[NumVetor];
	TpPilha Pilha[NumVetor];
	while (i<NumVetor)
	{
		Inicializar(Pilha[i]);
		
		Inserir (Pilha[i],'=');
		Inserir (Pilha[i],'=');
		Inserir (Pilha[i],'=');
		Inserir (Pilha[i],'=');
		Inserir (Pilha[i],'=');
		
		i++;
	}

		do
		{
			
			Vet=rand()%NumVetor; // Sorteia Qual vetor ira Alterar ;
			i=rand()%2+1; // Sorteira o que vai fazer no vetor ! ;
	     	Cor = rand()%(15)-1;//Sorteia a Cor
	     	if (i==1)
	     	{
	     		if (PilhaCheia(Pilha[Vet].Topo))
	     		{
	     			Retirar (Pilha[Vet]);
	     		}
	     		else
	     		{	  		
	     			Inserir(Pilha[Vet],'=');
	     		}
	     			     		
	     	}
	     	
	     	
	     	if (i==2) // 
	     	{
	     		if (PilhaVazia(Pilha[Vet].Topo))
	     		{	 
					 Inserir(Pilha[Vet],'=');	
	     		}
	     		else
	     		{	
	     			Retirar (Pilha[Vet]);
	     		}
	     		
	     	}
	     	
	     	y=0;
			clrscr();
			x=2;
			textcolor(Cor);
			while (y<NumVetor)
			{
				gotoxy (10,x);
				ExibePilha(Pilha[y]);
				y++;x++;x++;	
			}
			_sleep(100);
	     	
		}while(!kbhit());
}
