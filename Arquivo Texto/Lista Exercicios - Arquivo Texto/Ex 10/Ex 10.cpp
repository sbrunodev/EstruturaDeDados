#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>


void contaMil (char nomeArq1[50])
{
	
	FILE *Arq1 = fopen (nomeArq1,"w");
	int i;

	for(i=0;i<=1000;i++)
	{
		
		fprintf (Arq1,"%d",i); // Grava a variavel formatada ! 
		fputs ("\n",Arq1);
	}
	    fputs ("Bruno",Arq1);
	
	fclose(Arq1);

}

int main ()
{
	contaMil("ContaMil.txt");
			
}
