//FILA
//[  ][  ][  ][  ][  ][  ]
//[  ][  ][  ][  ][  ][  ]
//fila circular
#define maxfila 15
struct tpfila
{
	int inicio,fim,qtde;
	char fila[maxfila];
};
void inicializa(tpfila &f)
{
	f.inicio=0;
	f.fim=0;
	f.qtde=0;
}
int cheia(tpfila f)
{
	return f.qtde==maxfila;
}
int vazia(tpfila f)
{
	return f.qtde==0;
}
void push(tpfila &f,char elem)
{
	if(!cheia(f))
	{
        f.fila[f.fim]=elem;
		if(f.fim==maxfila-1)
		f.fim=0;
		else
		f.fim++;
		f.qtde++;
	}
	
}
char pop(tpfila &f)
{
	if(!vazia(f))
	{
		char test;
		test=f.fila[f.inicio];
		if(f.inicio==maxfila-1)
		f.inicio=0;
		else
		f.inicio++;
		f.qtde--;
		return test;		
	}
}

void exibe(tpfila f)
{
	while(!vazia(f))
	printf("%c",pop(f));
}
//fila com prioridades
//Os elementos entram no final da fila,mas devem ser deslocados até a sua posição,
//a ordem dos elementos
//eds
struct tpelemento
{
	char id;
	int prioridade;//1-alta /2-média /3-baixa 
};
struct tpfilap
{
	int inicio,fim,qtde;
	char fila[maxfila];	
};
//exemplo de uso
//inicialização inicio=0/fim=-1/qtde=0
//insere m >prioridade 2
//[m²][  ][  ][  ][  ][  ]
//inicio fim qtde
//insere A->prioridade:3
//[m²]   [a²][  ][  ][  ][  ]
//inicio fim
//[x¹   ][  m²][a³][  ][  ][  ][  ]
//inicio   fim qtde=3
//insere k->prioridade
// [x¹]  [k¹][m²][a³][ ][ ][ ]
//ini=0   1   2   3=fim
//reta=Obrigatoriamente, o elemento do início=portanto,deve retornar o x
//[] [k¹   ]   [m²][a³] 
//  inicio 1    1  fim   qtde=3
//implemente o tad para a fila com prioridade
//inserção direta
 

