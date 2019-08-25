#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>

struct TpFilme { char titulo[200], classificacao[30]; int producao, minutos; float gasto, renda, espectadores;};

bool leFilme (char nomeArq[40])
{
	FILE* arqTexto = fopen (nomeArq,"r");
	FILE* arqBinario = fopen ("filmesBinario.dat","wb");
	TpFilme F;
	
	if(arqTexto==NULL)
		return false;
	else
	{
		fscanf (arqTexto,"%s %d %s %f %f %d %f",&F.titulo,&F.producao,&F.classificacao,&F.gasto,&F.renda,&F.minutos,&F.espectadores);
	
		while (!feof(arqTexto))
		{
			fwrite (&F,sizeof(TpFilme),1,arqBinario);
		//	printf ("Titulo: %s \n Class: %s \n Prod: %d \n Min: %d \n Gasto: %.2f\n Renda: %.2f\n Espe: %.2f \n\n\n",F.titulo,F.classificacao,F.producao,F.minutos,F.gasto,F.renda,F.espectadores);		
		//	F.producao=0;F.minutos=0;F.gasto=0;F.renda=0;F.espectadores=0;	
				
			fscanf (arqTexto,"%s %d %s %f %f %d %f",&F.titulo,&F.producao,&F.classificacao,&F.gasto,&F.renda,&F.minutos,&F.espectadores);
		}
		return true;
	}
	fclose (arqTexto);
	fclose (arqBinario);
}


int main ()
{
	if (leFilme("Filme.txt")==true)
		printf ("Arquivo binario gerado com sucesso ! ");
	else
		printf ("Error !");
		
		
		FILE *arqBinario = fopen ("filmesBinario.dat","rb");
		TpFilme F;
		fread(&F,sizeof(TpFilme),1,arqBinario);
		while (!feof(arqBinario))
		{
		
			printf ("Titulo: %s \n Class: %s \n Prod: %d \n Min: %d \n Gasto: %.2f\n Renda: %.2f\n Espe: %.2f \n\n\n",F.titulo,F.classificacao,F.producao,F.minutos,F.gasto,F.renda,F.espectadores);
			
			
			fread(&F,sizeof(TpFilme),1,arqBinario);
		}		
		
		fclose (arqBinario);
		getch ();
		
}
