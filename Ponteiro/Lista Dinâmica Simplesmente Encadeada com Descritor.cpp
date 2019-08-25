#include <stdio.h>
#include <conio.h>

  struct TpPont 
  {
  	char Info;
  	TpPont *Prox;
  };
  
  struct TpDescritor 
  {
  	TpPont *Inicio, *Fim;
  	int Qtd;
  };
  
  //Declaração: TpDescritor Desc;//  [  |  |  ]
  
  void Inicializa (TpDescritor &Desc) 
  {						//	       	  Desc
  	Desc.Inicio = NULL; //  Null<--[  | 0 |  ]-->Null
  	Desc.Fim = NULL;
  	Desc.Qtd = 0;
  }
  
  TpPont *NovaCaixa (char Elem)
  {
  	 TpPont *Nc = new TpPont();
  	 Nc->Prox=NULL;
  	 Nc->Info=Elem;
  	 
  	 return Nc;	
  }
  
  void InsercaoElem (TpDescritor &Desc) 
  {
	printf ("Insere: ");
	char Elem;
	Elem = getche();
	
	while (Elem!=27)
	{
		TpPont *Caixa = NovaCaixa(Elem);
		
	 	if (Desc.Inicio == NULL)
	  	{
	  		Desc.Inicio = Caixa;
	  		Desc.Fim = Caixa;
	   	}	
	  	else
	  	{
	  		Caixa->Prox=Desc.Inicio;
	  		Desc.Inicio=Caixa;
	  	}
	  	
	  printf ("\nInsere: ");
	  Elem = getche();
	  char Elem;		
		
	} 		
  }
  
  void Exibe (TpDescritor Desc)
  {
  	printf ("\nExibe");
  	while (Desc.Inicio!=NULL)
  	{
  		  printf ("\n %c %x",Desc.Inicio->Info,Desc.Inicio->Prox);
		  Desc.Inicio=Desc.Inicio->Prox;
  		 		
  	}
  	
  }
  
  void InsercaoFinal (TpDescritor &Desc) 
  {
  		printf ("Insere: ");
	char Elem;
	Elem = getche();
	
	while (Elem!=27)
	{
		TpPont *Caixa = NovaCaixa(Elem);
		
	  	if (Desc.Inicio == NULL)
	  	{
	  		Desc.Inicio = Caixa;
	  		Desc.Fim = Caixa;
	   	}	
	  	else
	  	{
	  		Desc.Fim->Prox=Caixa;
	  		Desc.Fim = Caixa;
	  	}
	 
	  	
	  printf ("\nInsere: ");
	  Elem = getche();
	  char Elem;		
		
	} 		
  	
  }
  
  
  
  	
  int main ()
  {
  	TpDescritor Desc;
  	Inicializa (Desc);
  	InsercaoFinal(Desc);
  	Exibe (Desc);
  	
  	
  }
  
  		
  		
  
