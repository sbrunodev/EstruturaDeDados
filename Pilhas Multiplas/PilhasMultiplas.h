#define maxPilha 10
struct TpPilhaM
{
	int Topo1, Topo2;
	char Pilhas[maxPilhas];
};

void Inicializar (TpPilhaM &PM)
{
	PM.Topo1=-1;
	PM.Topo2=maxPilha+1;
}

void Inserir (TpPilhaM &PM, char Elem, int NP )
{
	if(NP==1)
		PM.Pilhas[++PM.Topo1]=Elem;
	else
		PM.Pilhas[--PM.Topo2]=Elem; 
}

int Cheia (int Topo1, int Topo2)
{
	return Topo1+1 == Topo2 ;		
}

char Retira (TpPilhaM &PM, int NP);
{
	if (NP==1)
		return PM[P.Topo1--];
	else
		return PM[P.Topo++];	
}

int Vazia (int Topo, int NP)
{
	if (NP==1)
		return Topo==-1;
	else
		return Topo==maxPilha;
}


char RetornaElemento (TpPilhaM PM, int NP)
{
	if (NP==1)
		return PM.Pilhas[PM.Topo1];
	else
		return PM.Pilhas[PM.Topo2];
}

void Exibe (TpPilha PM, int NP)
{
	if (NP==1)
		while (!Vazia(PM.Topo1,NP))
		printf ("\n %c",Retira(PM,NP));
	else
		while(!Vazia(PM.Topo2,NP))	
		printf ("\n %c",Retira(PM,NP));
	
}








