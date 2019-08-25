/*
	Pilhas Multiplas
	
	Probabilidade de armazenar várias listas com disciplina de acesso do tipo PILHA. (Listas Concorrentes)
	
	Caso 1: "2" Pilhas em um mesmo vetor
	[][][][][][][][][][]
	0 1 2 3 4 5 6 7 8 9
---->				<----
Topo1				 Topo2
(Pilha1)			 (Pilha2) 


	Pilhas Multiplas : caso 'n' Pilhas
	
bases:	[0][3][6][][][][][][][]
		0 1 2 3 4 5 6 7 8 9
		
Topos:	[-1][2][5][][][][][][][]
		0 1 2 3 4 5 6 7 8 9
		
Pilhas:	[][][]|[][][]|[][][][]
		0 1 2 3 4 5 6 7 8 9
	
*/

Ed's
#define maxPilha 10

struct TpPilhaM
{
	int Topo1, Topo2;
	char Pilhas[maxPilhas];
};

Operações Associadas 
void Inicializa (TpPilhaM &PM);
void Inserir (TpPilhaM &PM, char Elem, int NP );
char Retira (TpPilhaM &PM, int NP);
char Cheia (int Topo1, int Topo2)
int Vazia (int Topo,int NP);
char RetornaElemTopo (TpPilhaM PM, int NP);
void Exibe (TpPilha PM, int NP);

