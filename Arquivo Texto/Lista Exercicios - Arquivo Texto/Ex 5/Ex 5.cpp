#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>

void fazAposta (FILE *Aposta)
{
	Aposta = fopen ("Aposta.txt","a+");
	
	char op;
	int numAposta=0,nApos[7],i=0;
	char data [15];
	
	
	while (op!='n')
	{
		printf ("Informe a Data: ");
		fflush(stdin);
		gets(data);
		
		i=0;
		do
		{
			printf ("Informe o %d numero apostado: ",i);
			scanf ("%d",&nApos[i]);
			i++;
			
		}while (i<7);
		
		fprintf (Aposta,"%d %s  %d %d %d %d %d %d %d",numAposta,data,nApos[0],nApos[1],nApos[2],nApos[3],nApos[4],nApos[5],nApos[6]);
		fputc('\n',Aposta);
		numAposta++;
		
		printf ("Continuar ? (s/n)");
		fflush(stdin);
		scanf ("%c",&op);
	}
	fclose(Aposta);
	
	
}


int main ()
{
	FILE *Aposta;
	fazAposta (Aposta);

}
