Lista Dinâmica Duplamente Encadeada

	Possibilita o acesso aos endereços alocados
	dinamicamente em duas direções
	
	Cabeça
	[ ] ->[|X|]<->[|B|]<->[|A|]<->[|E|]-> NULL;
	
	struct TpPont
	{
		char Info;			[A|Info|P]	
		TpPont *Ant,*Prox;
	};
	
	Declaração:
			TpPont *Cabeca;
			
	Inicialização:			
			Cabeca = NULL; [| |] -> NULL
			
	Inserção no Início:
			TpPont *Caixa = NovaCaixa(Elem);
			Caixa->Prox = Cabeca; Cabeca=Caixa; // Lista Vazia;
			Caixa->Prox->Ant = Caixa; // Diferente de NULL;
			
	Inserção no Final:
			TpPont *p = Cabeca;
			whil (p->prox!=NULL) // Para onde tá apontando para NULL
				p = p->prox;
				
			Caixa->Ant=p;
			p->Prox=Caixa;
			
	Inserção no Meio:
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
