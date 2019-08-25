#include <stdio.h>
#include <conio2.h>

void Inverte (int TL,int Vetor[5])
{	
	if (TL==0)
		printf ("[%d] ",Vetor[TL]);
	else
	{
	  printf ("[%d] ",Vetor[TL]);	
	  Inverte (TL-1,Vetor);	
	}			
}

int main ()
{
	int Vetor [7] = {-1,0,1,2,3,4,5};
	int TL=8;
	Inverte (TL,Vetor);
}
