
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>

struct TpProduto 
{ int cod, qtd;
  float valor;	
  char desc[20];};
  
void geraTxt ()
{
	FILE *Arq = fopen ("Cadastrar.txt","a");
	TpProduto R;
	printf ("> Inserir produto ! \n\n");
	printf ("Codigo do Produto: ");
	scanf ("%d",&R.cod);
	while (R.cod>0)
	{
		printf ("Valor R$: ");
		scanf ("%f",&R.valor);
		printf ("Quantidade: ");
		scanf ("%d",&R.qtd);
		printf ("Descricao do produto: ");
		fflush(stdin);
		gets(R.desc);
		
		fprintf (Arq,"%d %d %f \t %s \n",R.cod,R.qtd,R.valor,R.desc);
		printf ("Concluido ! ");
		
		printf ("Codigo do Produto: ");
		scanf ("%d",&R.cod);
	}
	
	fclose (Arq);
	
}

void ExibeTxt ()
{
	FILE *Arq = fopen ("Produtos.txt","r");
	FILE *Arq2 = fopen ("Relatorio.txt","w");
	TpProduto R;
	if (Arq == NULL)
		printf (" ERROR ");
	else
	{
		fscanf (Arq,"%d %s %d %f",&R.cod,&R.desc,&R.qtd,&R.valor);
		while (!feof(Arq))
		{
   		   
	 	   fprintf (Arq2,"%d %s %d %2.f \n",R.cod,R.desc,R.qtd,R.valor);
	 	   
	 	   fscanf (Arq,"%d %s %d %f",&R.cod,&R.desc,&R.qtd,&R.valor);
		}

	}	
	
	fclose(Arq);
	fclose(Arq2);
}

int main ()
{
	//geraTxt();
	ExibeTxt();
}

