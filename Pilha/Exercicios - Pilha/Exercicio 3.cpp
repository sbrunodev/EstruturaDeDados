#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include "PilhaInt.h"

int main ()
{
	/*char Expressao [15];
	Expressao[0]='9';
	char c = Expressao[0];
	int x = c - '0';
	printf("%d",x);*/
   
 	char Expressao [15],caracter;
 	int Num1=0, Num2=0,x=0,i=0;
 	TpPilha Pilha;
 	Inicializar(Pilha);
 	
 	printf ("Informe a Expressao: ");
 	fflush(stdin);
 	gets(Expressao);
 	
 	while (i<15)
 	{
 		if (Expressao[i]!= '+' && Expressao[i]!= '-' && Expressao[i]!= '*' && Expressao[i]!= '/' && Expressao[i]!='\0')
 		{
 			caracter = Expressao[i];
			x = caracter - 0;	
 			Inserir(Pilha,x);	
 		}
 		else
 		{
 			if (!PilhaVazia(Pilha.Topo))
 			{
	 			 switch (Expressao[i])
				 {
				 	case '+' : Num1=Retirar (Pilha); Num2=Retirar (Pilha);
				 	printf ("%d + %d \n ",Num1,Num2);
				 	Inserir (Pilha,Num1+Num2);
				 	
				 	break;
				 	
				 	case '-' : Num1=Retirar (Pilha); Num2=Retirar (Pilha);
				 	Inserir (Pilha,Num1-Num2);
				 	printf ("Num1 - Num2 \n ",Num1,Num2);
				 	break;
				 	
				 	case '*' : Num1=Retirar (Pilha); Num2=Retirar (Pilha);
				 	Inserir (Pilha,Num1*Num2);
				 	printf ("Num1 * Num2 \n ",Num1,Num2);
				 	break;
				 	
				 	case '/' : Num1=Retirar (Pilha); Num2=Retirar (Pilha);
				 	Inserir (Pilha,Num1/Num2);
				 	printf ("Num1 / Num2 \n ",Num1,Num2);
				 	break;
				 	
				 }		
 			}
 			else
 				printf ("ERROR ");
			
 
 		}

	 i++;	
 	}
 	
 
}
