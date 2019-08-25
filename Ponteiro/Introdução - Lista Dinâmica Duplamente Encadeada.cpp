Lista Din�mica Duplamente Encadeada

	Possibilita o acesso aos endere�os alocados
	dinamicamente em duas dire��es
	
	Cabe�a
	[ ] ->[|X|]<->[|B|]<->[|A|]<->[|E|]-> NULL;
	
	struct TpPont
	{
		char Info;			[A|Info|P]	
		TpPont *Ant,*Prox;
	};
	
	Declara��o:
			TpPont *Cabeca;
			
	Inicializa��o:			
			Cabeca = NULL; [| |] -> NULL
			
	Inser��o no In�cio:
			TpPont *Caixa = NovaCaixa(Elem);
			Caixa->Prox = Cabeca; Cabeca=Caixa; // Lista Vazia;
			Caixa->Prox->Ant = Caixa; // Diferente de NULL;
			
	Inser��o no Final:
			TpPont *p = Cabeca;
			whil (p->prox!=NULL) // Para onde t� apontando para NULL
				p = p->prox;
				
			Caixa->Ant=p;
			p->Prox=Caixa;
			
	Inser��o no Meio:
			TpPont *p=Cabeca;
			while (p->Info < Caixa->Info)
				p = p->Prox;
			
			Caixa->Ant = p->Ant;
			Caixa->Prox = p;
			P->Ant = Caixa;
			Caixa->Ant->Prox=Caixa;
			
		
TpPont *NovaCaixa (char Elem)
{
	TpPont *Nc = new TpPont; // Nc [ ] - > [| |]
	Nc->Ant=NULL;
	Nc->Prox=NULL;
	Nc->Info=Elem;
	
	return Nc;
}
