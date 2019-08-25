#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>

void InverteRec(int Vet[], int TL, int VetInvertido[], int i)
{
	if (TL==0)
		VetInvertido[i]=Vet[TL];
	else
	{
		VetInvertido[i]=Vet[TL];
		TL--;
		i++;
		InverteRec(Vet,TL,VetInvertido,i);
	}
}

int main()
{
	int Vet[10], VetInvertido[10], TL=0, Num;
	
	printf ("Numero: ");
	scanf ("%d",&Num);
	while (Num>0 && TL<10)
	{
		Vet[TL]=Num;
		TL++;
		printf ("Numero: ");
		scanf ("%d",&Num);
	}
	int i=0;
	InverteRec (Vet,TL-1,VetInvertido,i);
	
	printf ("Vetor \n");
	for(i=0;i<TL;i++)
		printf ("[%d] ",Vet[i]);
	
	printf ("\nVetor Invertido \n");
	for(i=0;i<TL;i++)
		printf ("[%d] ",VetInvertido[i]);
	
}
