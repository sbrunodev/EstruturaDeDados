/*Arquivo Texto Formatado 

Leitura

	scanf (buffer,formatação,variaveis);
	
	fprintf (buffer,formatação,variaveis);
*/

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
	FILE *Arq = fopen ("Cadastrar.txt","r");
	TpProduto R;
	if (Arq == NULL)
		printf (" ERROR ");
	else
	{
		fscanf (Arq,"%d %d %f %s",&R.cod,&R.qtd,&R.valor,&R.desc);
		while (!feof(Arq))
		{
   		   
	 	   printf ("\n\n Cod: %d - Qtd: %d - Valor: %f - Desc: %s",R.cod,R.qtd,R.valor,R.desc);
	 	   
	 	   fscanf (Arq,"%d %d %f %s",&R.cod,&R.qtd,&R.valor,&R.desc);
		}

	
	}	
	
	fclose(Arq);
}

int main ()
{
	//geraTxt();
	ExibeTxt();
}

