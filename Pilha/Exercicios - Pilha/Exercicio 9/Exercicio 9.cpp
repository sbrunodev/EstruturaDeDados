#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include "Pilha.h"


int main ()
{
	char c,Palavra[15],Frase[100];
	int i=0,j=0,Aux=0;
	TpPilha Pilha;
	
	printf ("Informe a Frase: ");
	fflush (stdin);
	gets (Frase);
	
	
	
	while (i<strlen(Frase))
	{
	
		Aux=0;
		Palavra;
		do{
			
			Palavra[Aux] = Frase [j];		
			j++,Aux++;
			
		  }while(Frase[j]!=' ');
		j++;
		printf ("Pal: %s \n",Palavra);
		Inserir (Pilha,Palavra);
		
	}
	
	getch ();
}





