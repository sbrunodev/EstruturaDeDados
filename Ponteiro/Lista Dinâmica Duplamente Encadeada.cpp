#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

struct TpPont 
{
	char Info;
	TpPont *Ant, *Prox;
};

TpPont *Inicializa (TpPont *LD)
{
	LD = NULL;
	return LD;
}

TpPont *NovaCaixa (char Elem)
{
	TpPont *Nc = new TpPont ();
	Nc->Ant = NULL;
	Nc->Prox = NULL;
	Nc->Info = Elem;
	
	return Nc;
}

TpPont *InsOrdenada (TpPont *LD)
{
	printf (" Insercao Ordenada: ");
	char Elem;
	
	printf ("Elemento: ");
	Elem = getche ();
	while (Elem!=27)
	{
		TpPont *Caixa = NovaCaixa(Elem);
		TpPont *p = LD;	
		
			if (p!=NULL)
			{
				p=LD;
				while (p->Info < Caixa->Info)
					p = p->Prox;
				
				Caixa->Ant = p->Ant;
				Caixa->Prox = p;
				p->Ant;
				Caixa->Ant->Prox=Caixa;	
			}
			else
			{
				Caixa->Ant=p;
				p->Prox=Caixa;
			}
		
		printf ("Elemento: ");
		Elem = getche ();		
	}
	return LD;	
}

TpPont * InsInicio (TpPont *LD)
{
	printf (" Insercao Inicio: \n");
	char Elem;
	printf ("\n Elemento: ");
	Elem=getche();
	while (Elem!=27)
	{
		TpPont *Caixa = NovaCaixa(Elem);
		
		if (LD==NULL)
		{
			Caixa->Prox = LD;
			LD = Caixa;
		}			
		else
		{
			Caixa->Prox = LD;
			LD = Caixa;
			Caixa->Prox->Ant=Caixa;
		}
		
		printf ("\n Elemento: ");
		Elem=getche();
	}
	return LD;
		
}

void Exibe (TpPont *LD)
{
	printf ("\n\n Exibe: ");
	
	while (LD!=NULL)
	{
		printf("\n %c - %x",LD->Info,LD->Prox);
		LD = LD->Prox;
		
	}

}

int main ()
{
	TpPont *LDDE ; 
	LDDE = Inicializa (LDDE);
	LDDE = InsInicio (LDDE);
	Exibe (LDDE);
	getch();
}
