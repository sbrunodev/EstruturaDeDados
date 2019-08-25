/* Estruturas de dados com Disciplina de Acesso do tipo Pilha

	Conceito: "L I F O" Last in first out 
	
	Toda Manipulação deve ocorrer em apenas uma extremidade da Pilha, denominada de TOPO. */

ed1
#define maxPilha 10
struct TpPilha { int TOPO; char Pilha [maxPilha];};

// Operações para manipulação

void Inicializar (TpPilha &P);
void Inserir (TpPilha &P, char Elem);
void Retirar (TpPilha &P);
int PilhaVazia (int Topo);
int PilhaCheia (int Topo);
char retornarElem (TpPilha P);
void ExibePilha (TpPilha P); */
