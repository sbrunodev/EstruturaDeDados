/* Programa��o Din�mica
	
	Utiliza��o de Vari�veis para aloca��o e/ou libera��o de endere�os de memoria em tempo de execu��o ou seja, durante a execu��o 
	do programa.
	
	Declara��o 
				Tipo *pont; [-]-> Lixo
				
	Inicializa��o com valor NULO
				Pont = NULL; []-.
							    |
							    v
							    
	Tipos de Acesso:
		
		P=> Conte�do da variavel (Endere�o);
		&p=> endere�o do local da variavel na memoria;
		*pont=>Conte�do do endere�o vinculado a var�vel.
		
	Aloca��o:					libera��o:
		pont=new tipo;					free(pont); // Some com o endere�o de aloca��o, nada acontece com a variavel
		
		
*/	
Lista Din�mica Simplesmente Encadeada
		
struct TpPont
{
	char Info;
	TpPont *Prox;	
};

 Declara��o
	TpPont *Lista;	// A Lista aponta para um endere�o qualquer [-]-> ?
	
Iniclializa��o
	Lista=NULL; // Cria lista apontando para nada
	
	
   Lista
	[-]-> 	[ 'M' |-]->   
						   Lista 	TpPont	
	Lista = new TpPont; 	[-]-> 	[  |-]->    
	
	
	Lista->Info='M';    Lista 	TpPont	
						[-]-> 	[ 'M' |-]->   
										
						Lista 	TpPont	
	Lista->Prox=NULL; [-]-> 	[ 'M' |-]-> NULL;  
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

			  					    
