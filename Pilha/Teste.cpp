#include <stdio.h>
#include <conio2.h>
#include "Pilha.h"

char Menu ()
{
	int Op;
	clrscr();
	printf ("MENU \n\n");
	
	printf ("[1] - Inicializa \n");
	printf ("[2] - Inserir na Pilha \n");
	printf ("[3] - Retira da Pilha \n");
	printf ("[4] - Elemento do Topo \n");
	printf ("[5] - Exibir a Pilha \n\n");
	
	printf ("[ESC] - Finalizar");
	scanf ("%c",&Op);
	return Op;
}

void Executa ()
{
	TpPilha Pilha;
	int Op,Elem;
	
	do
	{	
		Op=Menu();
		
		switch (Op)
		{
			case '1' : Inicializar (Pilha); printf ("Pilha Inicializada ! "); break;
			
			case '2' : 
					{
						 printf ("Inserir na Pilha ");
					 	if (PilhaCheia(Pilha.Topo))
					 		printf ("Pilha Cheia! \n");
						else
						{
							printf ("Elem: ");
							Elem = getche();
							Inserir (Pilha,Elem);
							printf ("Insercao Realizada ! \n");
						}
		
					}	break;
					
				
				
			case '3' : printf ("Retirar da Pilha ");
					 if (PilhaVazia(Pilha.Topo))
					 	printf ("Pilha Vazia! \n");
					 else
					 	printf ("\n Excluido: %c \n",Retirar(Pilha));
					
					break;
					
			case '4' : if (PilhaVazia(Pilha.Topo))
							printf ("Pilha Vazia ! ");
								
						else
							printf ("%c",RetornaElem(Pilha));
							
							getch();

						break;
					
			case '5' : printf ("Elementos Pilha");
						ExibePilha(Pilha);getch ();break;
						
					
			
		}
		
		
		
	}while (Op!=27);
	
	
}


int main ()
{
	Executa();
	
}


