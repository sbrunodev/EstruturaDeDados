// Lista Dinâmica Simplesmente Encadeada com Descritor
/*
- O Descritor é um recurso utilizado para armazenar elementos comuns a lista
  e vincular acessos diretos aos seus extremos.
  Exemplo:
  				Descritor
  			 ----[ Ini |Q| Fim ]----
  			 |                      |
			 v  				    v
     	    [A|]--> [B|]-->[C|]-->[D|]-->Null
  
  
  Estrutura de Dados
*/
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
  	Desc.Qtde = 0;
  }
  
  
  void InsercaoElem (TpDescritor &Desc) 
  {
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
  		
  }
  
  void InsercaoFinal (TpDescritor &Desc) 
  {
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
  		
  }
  
  
  
  	
  int main ()
  {
  	
  	
  }
  
  		
  		
  
  
  
  
