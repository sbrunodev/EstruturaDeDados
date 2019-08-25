// Lista dinâmica simplesmente encadeada
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>


struct TpPont
{
	char Info;
	TpPont *Prox;
};
void Exibe (TpPont *Lista);
TpPont* Inicializa (TpPont *Lista)
{
	Lista = NULL;
	return NULL; // ou return NULL;
}

TpPont* Insere (TpPont *Lista)
{
	printf ("INSERE \n");
	TpPont *Caixa;
	char Elem;
	printf ("\n Elemento: ");
	Elem = getche();
	while (Elem!=27)
	{					    // Caixa	
		Caixa= new TpPont;  // [  ] -> [  |] // Quando executa esse comando novamente ele aponta para outro lugar qualquer.
		Caixa-> Info = Elem;// [  ] -> ['M'|] 
		Caixa->Prox = NULL; // [  ] -> ['M'|] -> NULL
		if ( Lista == NULL) // Lista [  ] -> NULL
			Lista = Caixa;  // Lista [  ] -> ['M'|] -> NULL
		else
		{
			Caixa->Prox = Lista;
			Lista = Caixa ; // Lista recebe o endereço que está na caixa.
			
		}	
		printf ("\n Elemento: ");
		Elem = getche();
	}
	printf ("\n\n\n");
	return Lista;
}

TpPont* InsereFim (TpPont *Lista)
{
	TpPont *Caixa,*Copia;
	char Elem;
	printf ("Inserir ");
	printf ("\n Elemento: ");
	Elem = getche();
	while (Elem!=27)
	{	
		Caixa = new TpPont;
		Caixa -> Info = Elem;
		Caixa -> Prox = NULL;
		if ( Lista == NULL )
			Lista = Caixa;
		else
		{
			Copia=Lista;
			while (Copia->Prox != NULL)
			{
				Copia = Copia->Prox;
			}
			Copia->Prox = Caixa; 
		} 
	
		printf ("\n Elemento: ");
		Elem = getche();
	}
	printf ("\n\n\n");
	return Lista;
}

TpPont* Excluir (TpPont *Lista)
{
	clrscr ();
	printf ("EXCLUI \n");
	TpPont *Antes, *Atual;
	char Elem;

	if (Lista != NULL)
	{
		printf (" Elemento a ser Retirado: ");
		Elem = getche();
		while (Elem !=27)
		{
			Atual = Lista;
			while (Atual!= NULL && Elem!=Atual->Info)
			{
				Antes = Atual;
				Atual = Atual -> Prox;
			}	
				
			if (Atual->Info==Elem) // Ou if ( Atual != Null )
			{	
				if (Atual == Lista) // Ou if ( Atual == NULL )
				{
					Lista = Atual->Prox;
				}	
				else
				{
					Antes->Prox = Atual->Prox;
				}
				printf ("\n Elemento Excluido ! ");
					
				delete(Atual);
			}
			else
				printf ("\n Elemento nao encontrado ! ");

			printf ("\n\n");
			printf (" Elemento a ser Retirado: ");
			Elem = getche();				
		}
	}
	else
	{
		printf ("Nenhum Elemento na Lista !");
	}
	printf ("\n\n\n");
	return Lista;	
}

TpPont *ExcluirTodosElem (TpPont *Lista)
{
	getch();
	printf ("\n\n Excluir todos Elementos \n");
	
	if (Lista != NULL)
	{
		TpPont *Atual;
		while (Lista!=NULL)
		{
			Atual = Lista;
			while (Atual->Prox!=NULL)
			{
				printf ("\n %c %x",Atual->Info,Lista);
				Atual = Atual->Prox;
				getch ();
				
			}	
			free(Atual->Prox);
			
		}		
		printf (" Elementos Excluidos ! "); getch();
	}
	else
	{
		printf ("Lista Vazia");getch();
	}
	return Lista;
}

void Exibe (TpPont *Lista)
{
	printf (" Exibe ");
	if (Lista == NULL)
		printf ("\n Lista Vazia !");
	else
		while (Lista != NULL)
		{
			printf ("\n %x = %c",Lista,Lista->Info);
			Lista=Lista->Prox;
		}
	printf ("\n\n");
	getch();
}

void PrimeiroElem (TpPont *Lista)
{

 	printf ("\n\n Primeiro Elemento: ");
	printf ("%c - %x",Lista->Info,Lista->Prox);	
}

void UltimoElemento (TpPont *Lista)
{

 	printf ("\n\n Ultimo Elemento: ");
    while (Lista->Prox!=NULL)
	{
		Lista = Lista->Prox;
	}
	 printf ("%c - %x",Lista->Info,Lista->Prox);		
}

void Consultar (TpPont *Lista)
{
	char Elem;
	printf (" Consultar \n");
	printf ("Elemento: "); 
	Elem = getche ();
	while (Lista!=NULL && Elem != Lista->Info)
		Lista = Lista->Prox;
		
	 printf ("\n %c - %x",Lista->Info,Lista->Prox);	
}

TpPont* InserirEntreElementos (TpPont *Lista)
{
	printf (" Inserir entre dois Elementos \n");
	char A,B;
	printf ("Informe o primeiro ELemento: ");scanf ("%c",&A);
	printf ("\n Informe o Segundo ELemento: ");scanf ("%c",&B);
	
}



int main ()
{
	TpPont *L;
	
	L=Inicializa (L);
	L=InsereFim(L);Exibe (L);
	Consultar(L);
	PrimeiroElem(L);
	UltimoElemento (L);
	L=ExcluirTodosElem(L);
//	L=Excluir (L);
	Exibe (L);
	
	return 0;
}
