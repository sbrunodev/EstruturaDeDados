#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct TpFabrica { int Codigo, Maquina; char Descricao[20], Data[9], Hora[9];};

char Menu ()
{
	clrscr();
	printf ("MENU\\\n\n");
	
	printf ("[C] - Cadastrar Producao \n");
	printf ("[R] - Relatorio Geral/Maquinas \n\n");
	
	printf ("[ESC] - Sair ");
	
	return toupper(getche());
}

int BuscaCodigo (FILE *Fabrica, int Procura)
{
	TpFabrica F;
	
	rewind (Fabrica);
	
	fread (&F,sizeof(TpFabrica),1,Fabrica);
		while (!feof(Fabrica) && Procura != F.Codigo)
				fread (&F,sizeof(TpFabrica),1,Fabrica);
	
	if (Procura == F.Codigo)
		return ftell (Fabrica) - sizeof(TpFabrica);
	else
		return -1;
			
}


void CadastrarProducao (FILE *Fabrica)
{
	
	
	TpFabrica P;
	int PosCodigo=0;
	Fabrica = fopen ("ProducaoGeral.dat","ab+");
	
	clrscr();
	printf ("MENU\\CADASTRAR PRODUCAO \n");
	printf ("\n> Codigo:");
	scanf ("%d",&P.Codigo);
	
	while (P.Codigo!=0)
	{
		
		PosCodigo = BuscaCodigo (Fabrica,P.Codigo);
		
		if (PosCodigo==-1)
		{
			printf ("\n> Descricao: ");
			fflush(stdin);
			gets(P.Descricao);
			
			_strdate(P.Data);
			_strtime(P.Hora);
			
			do{
				printf ("\n> Maquina: [1] [2] [3]");
				scanf("%d",&P.Maquina);
				
			  }while (P.Maquina<1 && P.Maquina>3);
			  
			fwrite (&P,sizeof(TpFabrica),1,Fabrica);
			printf ("\t\n\n Produto Armazenado ! ");
			getch();
		}
		else
		{
			printf (" \n\t Produto ja Cadastrado ! ");getch();
		}
		
		
	clrscr();
	printf ("MENU\\CADASTRAR PRODUCAO \n\n");
	printf ("> Codigo:");
	scanf ("%d",&P.Codigo);
	}
	
	fclose (Fabrica);
}


char MenuRelatorio ()
{
	clrscr();
	printf ("MENU\\RELATORIOS\\\n\n");
	
	printf ("[C] - Relatorio Geral \n");
	printf ("[A] - Relatorio Maquina [1] \n");
	printf ("[S] - Relatorio Maquina [2] \n");
	printf ("[D] - Relatorio Maquina [3] \n\n");
	
	printf ("[ESC] - Sair ");
	
	return toupper(getche());
	
}


void RelatorioMaquina1 (FILE *Fabrica)
{
	clrscr();
	printf ("MENU\\RELATORIOS\\RELATORIO MAQUINA[1] \n\n");
	
	Fabrica = fopen ("ProducaoGeral.dat","rb");
	FILE* Maquina1 = fopen ("Maquina1.dat","wb");
	TpFabrica F;
	
	if (Fabrica==NULL)
		printf ("\t Arquivo Vazio ! ");
	
	else
	{
		printf (" Codigo \tDescisao \tData  \t   Hora\t      Maquina \n");
		fread (&F,sizeof(TpFabrica),1,Fabrica);
		while (!feof(Fabrica))
		{
			if (F.Maquina==1)
			{
				printf (" %d \t   %s  \t      %s \t  %s \t%d\n",F.Codigo,F.Descricao,F.Data,F.Hora,F.Maquina);
				fwrite (&F,sizeof(TpFabrica),1,Maquina1);
			}
		
			fread (&F,sizeof(TpFabrica),1,Fabrica);
		}
		getch();
	}
	
	fclose(Fabrica);
	fclose(Maquina1);
}

void RelatorioMaquina2 (FILE *Fabrica)
{
	clrscr();
	printf ("MENU\\RELATORIOS\\RELATORIO MAQUINA[2] \n\n");
	
	Fabrica = fopen ("ProducaoGeral.dat","rb");
	FILE* Maquina2 = fopen ("Maquina2.dat","wb");
	TpFabrica F;
	
	if (Fabrica==NULL)
		printf ("\t Arquivo Vazio ! ");
	
	else
	{
		printf (" Codigo \tDescisao \tData  \t   Hora\t      Maquina \n");
		fread (&F,sizeof(TpFabrica),1,Fabrica);
		while (!feof(Fabrica))
		{
			if (F.Maquina==2)
			{
				printf (" %d \t   %s  \t      %s \t  %s \t%d\n",F.Codigo,F.Descricao,F.Data,F.Hora,F.Maquina);
				fwrite (&F,sizeof(TpFabrica),1,Maquina2);
			}
		
			fread (&F,sizeof(TpFabrica),1,Fabrica);
		}
		getch();
	}
	
	fclose(Fabrica);
	fclose(Maquina2);
}


void RelatorioMaquina3 (FILE *Fabrica)
{
	clrscr();
	printf ("MENU\\RELATORIOS\\RELATORIO MAQUINA[3] \n\n");
	
	Fabrica = fopen ("ProducaoGeral.dat","rb");
	FILE* Maquina3 = fopen ("Maquina3.dat","wb");
	TpFabrica F;
	
	if (Fabrica==NULL)
		printf ("\t Arquivo Vazio ! ");
	
	else
	{
		printf (" Codigo \tDescisao \tData  \t   Hora\t      Maquina \n");
		fread (&F,sizeof(TpFabrica),1,Fabrica);
		while (!feof(Fabrica))
		{
			if (F.Maquina==3)
			{
				printf (" %d \t   %s  \t      %s \t  %s \t%d\n",F.Codigo,F.Descricao,F.Data,F.Hora,F.Maquina);
				fwrite (&F,sizeof(TpFabrica),1,Maquina3);
			}
		
			fread (&F,sizeof(TpFabrica),1,Fabrica);
		}
		getch();
	}
	
	fclose(Fabrica);
	fclose(Maquina3);
}

void RelatorioGeral (FILE *Fabrica)
{
	clrscr();
	printf ("MENU\\RELATORIOS\\RELATORIO GERAL \n\n");
	
	Fabrica = fopen ("ProducaoGeral.dat","rb");
	TpFabrica F;
	
	if (Fabrica==NULL)
		printf ("\t Arquivo Vazio ! ");
	
	else
	{
		printf (" Codigo \tDescisao \tData  \t   Hora\t      Maquina \n");
		fread (&F,sizeof(TpFabrica),1,Fabrica);
		while (!feof(Fabrica))
		{
			printf (" %d \t   %s  \t      %s \t  %s \t%d\n",F.Codigo,F.Descricao,F.Data,F.Hora,F.Maquina);
			fread (&F,sizeof(TpFabrica),1,Fabrica);
		}
		getch();
	}
	
	fclose(Fabrica);
}


void ExecutaRelatorio(FILE *Fabrica)
{
	char Op;
	
	do{
		
		Op=MenuRelatorio();
		
		switch (Op)
		{
			case 'C':RelatorioGeral(Fabrica);break;
			case 'A':  RelatorioMaquina1(Fabrica);break;
			case 'S':  RelatorioMaquina2(Fabrica);break;
			case 'D':  RelatorioMaquina3(Fabrica);break;
		}
		
		
		
	}while (Op!=27);
	
}


void Executa ()
{
	FILE *Fabrica;
	TpFabrica Producao;
	char Op;
	
	do{
		
		Op=Menu();
		switch (Op)
		{
			case 'C': CadastrarProducao(Fabrica);break;
			case 'R': ExecutaRelatorio(Fabrica);break;
			
			
		}
	
	}while(Op!=27);
}




int main ()
{
	Executa ();
	
}
