#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>



void resultado (int numAposta, char data[15], int contaPremios)
{
	if (contaPremios==3)
		printf ("Num Aposta: %d - Data: %s - Acertos: %d Terno ! \n",numAposta,data,contaPremios);
		
	if (contaPremios==4)
		printf ("Num Aposta: %d - Data: %s - Acertos: %d Quadra ! \n",numAposta,data,contaPremios);	
		
	if (contaPremios==5)
		printf ("Num Aposta: %d - Data: %s - Acertos: %d Quina ! \n",numAposta,data,contaPremios);		
}

void Premiadas (char nomeArq[15])
{
	FILE *arqAposta = fopen (nomeArq,"r");
	int numAposta=0,nApos[7],premiadas[7],i=0,j=0,contaPremios=0;
	char data [15];
	
	do
	{
		printf ("Informe o %d numero Premiado: ",i+1);
		scanf ("%d",&premiadas[i]);
		i++;
	}while (i<5);
	i=0;
	
	
	
	
	if (arqAposta == NULL)
		printf ("Erro !");
	else
	{
		fscanf (arqAposta,"%d %s %d %d %d %d %d %d %d",&numAposta,&data,&nApos[0],&nApos[1],&nApos[2],&nApos[3],&nApos[4],&nApos[5],&nApos[6]);
		while (!feof(arqAposta))
		{	
			printf ("\n %d %s %d %d %d %d %d %d %d \n ",numAposta,data,nApos[0],nApos[1],nApos[2],nApos[3],nApos[4],nApos[5],nApos[6]);
			contaPremios=0;
			for(j=0;j<5;j++)
			{
				for(i=0;i<7;i++)
				{
					if(premiadas[j]==nApos[i])
					{
						contaPremios++;	
					}
								
				}	
			}
			resultado (numAposta,data,contaPremios);
			
				
			fscanf (arqAposta,"%d %s %d %d %d %d %d %d %d",&numAposta,&data,&nApos[0],&nApos[1],&nApos[2],&nApos[3],&nApos[4],&nApos[5],&nApos[6]);
		}	
	}

	fclose (arqAposta);
	getch ();
}

int main ()
{
	Premiadas ("Aposta.txt");
	
	
}
