#define maxPilha 10

struct TpPilha { int Topo; char Pilha [maxPilha];};


void Inicializar (TpPilha &P)
{
	P.Topo=-1;	
}


void Inserir (TpPilha &P, char Elem)
{
	P.Pilha[++P.Topo]=Elem;	
}


char Retirar (TpPilha &P)
{
	return P.Pilha[P.Topo--];
}
 

int PilhaVazia (int Topo)
{
	return Topo == -1;
	/*
	if (Topo==-1)
		return 1
	else
		return 0
	*/
}


int PilhaCheia (int Topo)
{
	return Topo== maxPilha-1;	
}


char RetornaElem (TpPilha P)
{
	return P.Pilha[P.Topo];
}


void ExibePilha (TpPilha P)
{
	while (!PilhaVazia(P.Topo))
		printf (" %c",Retirar(P));
}

















