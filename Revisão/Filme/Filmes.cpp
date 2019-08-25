#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct TpFilme {char Titulo[20], Classificacao [10]; float Gasto,Renda,Taxa;int Minutos,Producao;};



char Menu ()
{
	clrscr();
	printf ("MENU\\\n\n");
	
	printf ("[ C ] - Cadastrar Filmes \n");
	printf ("[ R ] - Relatorios\n");
	printf ("[ L ] - Filme com Maior Lucro \n");
	printf ("[ D ] - Ducarao Media\n");
	printf ("[ E ] - Filme com Maior Taxa de Espectadores\n");
	printf ("[ O ] - Ordenar pelo ano de Producao \n");
	printf ("[ V ] - Valor Mediano paro ano de Producao \n\n");
	printf ("[ESC] - Sair ");
	
	return toupper(getche());	
}

char MenuRelatorio ()
{
	clrscr();
	printf ("MENU\\RELATORIO\n\n");
	
	printf ("[ R ] - Classificao R \n");
	printf ("[ G ] - Classificao G \n");
	printf ("[ A ] - Classificao PG-13 \n\n");
	
	printf (" [ESC] - Voltar ");
	
	
	return toupper (getche());
	
}


int BuscaFilme (FILE *Filme, char Procura [20])
{
	TpFilme F;
	rewind (Filme);
	fread (&F,sizeof(TpFilme),1,Filme);
		while (!feof(Filme) && strcmp (F.Titulo,Procura)!=0)
			fread (&F,sizeof(TpFilme),1,Filme);
			
	if (strcmp (F.Titulo,Procura)==0)		
		return ftell (Filme) - sizeof(TpFilme);
	else
		return -1;		
	
}

void CadastrarFilmes (FILE *Filme)
{
	TpFilme F;
	clrscr();
	int PosFilme;
	Filme = fopen ("Filme.dat","ab+");
	
	printf ("MENU\\CADASTRAR FILME \n\n");
	
	printf ("> Titulo: ");
	fflush(stdin);
	gets(F.Titulo); //toupper (F.Titulo);
	
	while (strcmp (F.Titulo,"\0")!=0)
	{
		PosFilme = BuscaFilme(Filme,F.Titulo);
		if (PosFilme==-1)
		{
			printf ("> Producao: ");
			scanf("%d",&F.Producao);
			
		    do{
			  printf ("> Classificacao: [R/PG-13/G] ");
			  fflush(stdin);
			  gets(F.Classificacao);	
				
			}while (strcmp(F.Classificacao,"r")!=0 && strcmp(F.Classificacao,"g")!=0 && strcmp(F.Classificacao,"pg-13")!=0  );
			
			printf ("> Gasto: (Milhoes)");
			scanf ("%f",&F.Gasto);
			
			printf ("> Renda: (Milhoes)");
			scanf ("%f",&F.Renda);
			
			printf ("> Duracao: (Minutos)");
			scanf ("%d",&F.Minutos);
			
			printf ("> Taxa de espectadores:");
			scanf ("%f",&F.Taxa);
			
		    fwrite (&F,sizeof(TpFilme),1,Filme);
			
			printf ("\n\t Cadastro Concluido !");getch ();
			
		}
		else
		{			
			/*fseek (Filme,PosFilme,0);	
		    printf (" Filme: %s \n",F.Titulo);
			printf (" Producao: %d \n",F.Producao);
			printf (" Classificacao: %s \n",F.Classificao);
			printf (" Gasto: %2.f \n",F.Gasto);
			printf (" Renda: %2.f \n",F.Renda);
			printf (" Duracao: %d \n",F.Minutos);
			printf (" Espectadores: %2.f\n",F.Taxa); */
			
			printf ("\n\t Filme ja cadastrado ! ");getch ();
		
			
		}
							
	//============================================
	clrscr();
	
	printf ("MENU\\CADASTRAR FILME \n\n");
		
	printf ("> Titulo: ");
	fflush(stdin);
	gets(F.Titulo); //toupper (F.Titulo);
				
	}	
	
	fclose (Filme);
}



void DuracaoMedia (FILE *Filme)
{
	
	clrscr();
	printf ("MENU\\DURACAO MEDIA \n");
	Filme = fopen ("Filme.dat","rb");


	TpFilme F;
	int SomaDuracao=0, TotalFilmes=0;
	fread (&F,sizeof(TpFilme),1,Filme);	

	if (Filme != NULL)
	{
	 while (!feof(Filme))
	   {	
			SomaDuracao+=F.Minutos;
			TotalFilmes++;
			fread (&F,sizeof(TpFilme),1,Filme);
	   }
	
	
	printf ("\t\nDuracao Media: %d",SomaDuracao/TotalFilmes);	
	}
	else
	{
		printf ("Arquivo Vazio ! ");
	}
	  

	getch ();
	fclose (Filme);
	
	
}

void FilmeMaiorLucro (FILE *Filme)
{
	TpFilme F, Aux;
	
	Filme = fopen ("Filme.dat","rb");
	
	clrscr();
	printf ("MENU\\FILME MAIOR LUCRO \n\n ");
	
	Aux.Renda=0;
	fread (&F,sizeof(TpFilme),1,Filme);
	while(!feof(Filme))
	{
		if (F.Renda > Aux.Renda)
			Aux = F;
		
		fread (&F,sizeof(TpFilme),1,Filme);	
	}
	
	
		
	printf ("Filme: %s \n",Aux.Titulo);
	printf (" Producao: %d \n",Aux.Producao);
	printf (" Classificacao: %s \n",Aux.Classificacao);
	printf (" Gasto: %2.f \n",Aux.Gasto);
	printf (" Renda: %2.f \n",Aux.Renda);
	printf (" Duracao: %d \n",Aux.Minutos);
	printf (" Espectadores: %2.f\n",Aux.Taxa); 
	
	getch ();
	
}

void FilmeMaiorTaxa (FILE *Filme)
{
	TpFilme F, Aux;
	
	Filme = fopen ("Filme.dat","rb");
	
	clrscr();
	printf ("MENU\\FILME MAIOR TAXA (ESPECTADORES) \n\n ");
	
	Aux.Taxa=0;
	fread (&F,sizeof(TpFilme),1,Filme);
	while(!feof(Filme))
	{
		if (F.Taxa > Aux.Taxa)
			Aux = F;
		
		fread (&F,sizeof(TpFilme),1,Filme);	
	}
	
	
		
	printf ("Filme: %s \n",Aux.Titulo);
	printf (" Producao: %d \n",Aux.Producao);
	printf (" Classificacao: %s \n",Aux.Classificacao);
	printf (" Gasto: %2.f \n",Aux.Gasto);
	printf (" Renda: %2.f \n",Aux.Renda);
	printf (" Duracao: %d \n",Aux.Minutos);
	printf (" Espectadores: %2.f\n",Aux.Taxa); 
	
	fclose (Filme);
	getch ();
}


void ClassificacaoR (FILE *Filme)
{
	clrscr();
	printf ("MENU\\RELATORIO\\CLASSIFICAO R\n\n");
	
	TpFilme F;
	Filme = fopen ("Filme.dat","rb");
	
	fread(&F,sizeof(TpFilme),1,Filme);
	if (Filme!=NULL)
	{
		while (!feof(Filme))
		{
			if (strcmp (F.Classificacao,"r")==0)
			{
			    printf (" Filme: %s \n",F.Titulo);
				printf (" Producao: %d \n",F.Producao);
				printf (" Classificacao: %s \n",F.Classificacao);
				printf (" Gasto: %2.f \n",F.Gasto);
				printf (" Renda: %2.f \n",F.Renda);
				printf (" Duracao: %d \n",F.Minutos);
				printf (" Espectadores: %2.f\n",F.Taxa);
				
				printf ("____________________________________ \n");		
			}
			
			fread(&F,sizeof(TpFilme),1,Filme);
		}
	}
	else
		printf ("Arquivo Vazio ! ");
	getch();
	fclose (Filme);
}

void ClassificacaoG (FILE *Filme)
{
	clrscr();
	printf ("MENU\\RELATORIO\\CLASSIFICAO G\n\n");
	
	TpFilme F;
	Filme = fopen ("Filme.dat","rb");
	
	fread(&F,sizeof(TpFilme),1,Filme);
	if (Filme!=NULL)
	{
		while (!feof(Filme))
		{
			if (strcmp (F.Classificacao,"g")==0)
			{
			    printf (" Filme: %s \n",F.Titulo);
				printf (" Producao: %d \n",F.Producao);
				printf (" Classificacao: %s \n",F.Classificacao);
				printf (" Gasto: %2.f \n",F.Gasto);
				printf (" Renda: %2.f \n",F.Renda);
				printf (" Duracao: %d \n",F.Minutos);
				printf (" Espectadores: %2.f\n",F.Taxa);
				
				printf ("____________________________________ \n");		
			}
			
			fread(&F,sizeof(TpFilme),1,Filme);
		}
	}
	else{
		printf ("Arquivo Vazio ! ");
	}
		
		
	getch();
	fclose (Filme);
}

void ClassificacaoPG13 (FILE *Filme)
{
	clrscr();
	printf ("MENU\\RELATORIO\\CLASSIFICAO PG-13\n\n");
	
	TpFilme F;
	Filme = fopen ("Filme.dat","rb");
	
	fread(&F,sizeof(TpFilme),1,Filme);
	if (Filme!=NULL)
	{
		while (!feof(Filme))
		{
			if (strcmp (F.Classificacao,"pg-13")==0)
			{
			    printf (" Filme: %s \n",F.Titulo);
				printf (" Producao: %d \n",F.Producao);
				printf (" Classificacao: %s \n",F.Classificacao);
				printf (" Gasto: %2.f \n",F.Gasto);
				printf (" Renda: %2.f \n",F.Renda);
				printf (" Duracao: %d \n",F.Minutos);
				printf (" Espectadores: %2.f\n",F.Taxa);
				
				printf ("____________________________________ \n");		
			}
			
			fread(&F,sizeof(TpFilme),1,Filme);
		}
	}
	else{
		printf ("Arquivo Vazio ! ");
	}
		
		
	getch();
	fclose (Filme);
}



void ExeRelatorio (FILE *Filme)
{
	char Op;
	
	do{
		Op=MenuRelatorio();
		
		switch (Op)
		{
			case 'R' : ClassificacaoR (Filme);break;
			case 'G' : ClassificacaoG (Filme);break;
			case 'A' : ClassificacaoPG13(Filme);break;
		}
		
		
		
	}while (Op!=27);
	
}

void OrdenarPeloAnoProducao (FILE *Filme)
{
	clrscr ();
	printf ("MENU\\ORDENAR POR ANO DE PRODUCAO");
	
	TpFilme F, Aux;
	int Tam,i,j;
	Filme = fopen ("Filme.dat","rb+");
	FILE *OrdenadoProducao = fopen ("OrdenadoProducao.dat","ab");
	

	if (Filme != NULL )
	{
		fseek (Filme,0,2);
	
		Tam = ftell (Filme)/sizeof(TpFilme);
		printf ("Tam %d",Tam);getch ();
		for (i=0;i<Tam-1;i++)
		{
			for (j=i+1;j<Tam;j++)
			{
				fseek (Filme,i*sizeof(TpFilme),0);
				fread(&F,sizeof(TpFilme),1,Filme);
				fseek (Filme,j*sizeof(TpFilme),0);
				fread(&Aux,sizeof(TpFilme),1,Filme);
				
				if ( F.Producao >  Aux.Producao)
				{
					fseek (Filme,j*sizeof(TpFilme),0);
					fwrite (&F,sizeof(TpFilme),1,Filme);
					fseek (Filme,i*sizeof(TpFilme),0);
					fwrite (&Aux,sizeof(TpFilme),1,Filme);
				}
			}
	
		}
	
	}
	else
		printf ("Arquivo Vazio !");
	

	
fclose (Filme);
	printf (" Arquivo Ordenado ! ");getch ();
}


void ValorMedianoProducao (FILE *Filme)
{
	clrscr();
	printf ("MENU\\VALOR MEDIANO POR PRODUCAO\n\n");
	
	Filme = fopen ("Filme.dat","rb");
	TpFilme F;	
	int Tam=0,Guarda=0;
	
	fread (&F,sizeof(TpFilme),1,Filme);
	if(Filme!=NULL)
	{
		Tam = ftell (Filme)/sizeof(TpFilme);
	
		if (Tam%2==0)
		{
			fseek (Filme,Tam,0);
			printf ("\t Ano Medio: %d",&F.Producao);
		}
		else
		{	
			
			fseek (Filme,Tam+1,0);
			Guarda=F.Producao;
			fseek(Filme,Tam-1,0);
			Guarda+=F.Producao;
			printf ("\t Ano Medio: %d", (Guarda/2));
		}
			
	}
		
		
	else
		printf ("Arquivo Vazio");
		
		
	
	getch ();
	fclose(Filme);
}


void Executa ()
{
	char Op;
	TpFilme F;
	FILE *Filme;
	
	do
	{
		Op=Menu();
		
		switch (Op)
		{
			case 'C' : CadastrarFilmes(Filme); break;
			case 'R' : ExeRelatorio (Filme);break;
			case 'L' : FilmeMaiorLucro(Filme);break;
			case 'D' : DuracaoMedia (Filme);break;
			case 'E' : FilmeMaiorTaxa (Filme);break;
			case 'O' : OrdenarPeloAnoProducao (Filme);break;
			case 'V' : ValorMedianoProducao (Filme);
			
			
		}
		
		
	}while(Op!=27);
}



int main ()
{
	Executa();
	
}
