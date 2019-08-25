/* Programação Dinâmica
	
	Utilização de Variáveis para alocação e/ou liberação de endereços de memoria em tempo de execução ou seja, durante a execução 
	do programa.
	
	Declaração 
				Tipo *pont; [-]-> Lixo
				
	Inicialização com valor NULO
				Pont = NULL; []-.
							    |
							    v
							    
	Tipos de Acesso:
		
		P=> Conteúdo da variavel (Endereço);
		&p=> endereço do local da variavel na memoria;
		*pont=>Conteúdo do endereço vinculado a varável.
		
	Alocação:					liberação:
		pont=new tipo;					free(pont); // Some com o endereço de alocação, nada acontece com a variavel
		
		
*/	
Lista Dinâmica Simplesmente Encadeada
		
struct TpPont
{
	char Info;
	TpPont *Prox;	
};

 Declaração
	TpPont *Lista;	// A Lista aponta para um endereço qualquer [-]-> ?
	
Iniclialização
	Lista=NULL; // Cria lista apontando para nada
	
	
   Lista
	[-]-> 	[ 'M' |-]->   
						   Lista 	TpPont	
	Lista = new TpPont; 	[-]-> 	[  |-]->    
	
	
	Lista->Info='M';    Lista 	TpPont	
						[-]-> 	[ 'M' |-]->   
										
						Lista 	TpPont	
	Lista->Prox=NULL; [-]-> 	[ 'M' |-]-> NULL;  
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

			  					    
