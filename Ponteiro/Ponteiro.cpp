#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

struct TpPont 
{
	char Elem;
	TpPont *Prox;
	
};


TpPont* Inicializa (TpPont *Lista)
{
	Lista = NULL;
	return NULL; // ou return NULL;
}

TpPont* Inserir (TpPont *Lista)
{
	system("cls");
	printf (" INSERIR\n");
	char Elem;
	TpPont* Caixa;
	printf ("\n Elemento: ");
	Elem = getche ();
	while (Elem!=27)
	{
		
		Caixa = new TpPont;
		Caixa->Elem=Elem;
		Caixa->Prox= NULL;
		
		if (Lista == NULL)
			Lista = Caixa;
		else
			Caixa->Prox = Lista;
			Lista=Caixa;
		
		
		printf ("\n Elemento: ");
		Elem = getche ();
	}
	
	return Lista;
}

char Menu ()
{
	system("cls");
	printf ("Ponteiro \n\n");
	
	printf (" [I] - Inserir \n");
	printf (" [R] - Retira \n");
	printf (" [E] - Exibe \n");
	
	return toupper (getche());
}

void Exibe (TpPont *Lista)
{
	system("cls");
	printf ("EXIBE \n ");
	if ( Lista == NULL)
		printf (" Lista Vazia ");
	else
		while (Lista!=NULL)
		{
			printf ("\n %c - %x",Lista->Elem,Lista);
			Lista = Lista->Prox;
		}	
		getch ();
}

TpPont* Retira (TpPont *Lista)
{
	system("cls");
	printf ("RETIRA\n");
	char Elem;
	printf ("Elemento: ");
	Elem = getche ();
	while (Elem!=27)
	{
		TpPont *Atual, *Antes;
		Antes=NULL;
		Atual=Lista;
		
		while (Atual->Prox!=NULL && Elem != Atual->Elem)
		{
			Antes = Atual;
			Atual = Atual -> Prox;
		}
		
		if (Atual->Elem==Elem)
		{
			if (Atual==NULL)
				Lista = Atual->Prox;
			else
				Antes->Prox = Atual->Prox;
			
			printf ("Elemento Excluido ! \n");	
			
			delete (Atual);
			
		}
		else
			printf ("  Elemento nao encontrado !\n ");
				
		printf ("Elemento: ");
		Elem = getche ();
	}
	
	return Lista;
}

void Executa ()
{
	TpPont *L;
	L = Inicializa (L);
	char Op;
	do
	{
		Op = Menu ();
		switch (Op)
		{
			case 'I' : L = Inserir (L); break;
			case 'R' : L = Retira (L);break;
			case 'E' : Exibe (L);break;
		}
		
		
	}while (Op!=27);
	
}

int main ()
{
	Executa ();

}


