//ao receber um arquivo texto e uma palavra, retorne a linha que mais tem essa palavra

//NAO FUNCIONA CASO A PALAVRA ESTEJA COM ACENTOS OU " Ç "

//IGNORA VIRGULA E PONTO, NAO PESQUISAR EX: "nome," ou "nome."  PESQUISAR SOMENTE: "nome"

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

int linha_da_palavra(char nomeArq[30], char palavra[30])
{
	FILE *arq=fopen(nomeArq,"r");
	char letra;
	char aux_palavra[30];
	int i=0, cont_maior=0, cont=0, linha=1, linha_maior=0, flag=0;
	
	rewind(arq);
	if(!arq)
	{
		fclose(arq);
		printf("\nArquivo não existe!\n\n");
		return 0;
	}
	else
	{
		aux_palavra[i]='\0';
		
		letra=fgetc(arq);
		while(!feof(arq))
		{
			if(letra!=' ' && letra!='\n' && letra!=',' && letra!='.')
			aux_palavra[i++]=letra; //atribui letra por letra
			else
			{
				if(letra=='\n') //caso mude de linha
				{
					cont=0;
					linha++;
				}
				aux_palavra[i]='\0';
				if(strcmp(aux_palavra,palavra)==0) //achou uma palavra
				  {
				    cont++; // printf("%d",linha);getch();
				    flag=1;
				 }
				 
				 if(cont_maior==0) //caso é a primeira linha 
					cont_maior=cont;
					else
					if(cont_maior<cont) //caso na linha anterior existe mais palavras
					{
					  linha_maior=linha;
					  
				      cont_maior=cont;
					}
					
							
				  i=0;
			}
			
			letra=fgetc(arq);
			
			if(feof(arq))
			aux_palavra[i]='\0';
		}
	}
	
	fclose(arq);
	
	if(linha_maior==0 && flag==1)
		{
			linha_maior=1;
			printf("  aaaa");getch();
		}
	else
		if(flag==0 && strcmp(aux_palavra,palavra)==0)
			linha_maior=1;
	
	if(linha_maior==0)
	return NULL;
	else
	return linha_maior;
}

int main()
{
	char nomeArq[30], palavra[30];
	int linha;
	
	setlocale(LC_ALL,"portuguese");
	
	printf("Qual o nome do arquivo?");
	fflush(stdin);
	gets(nomeArq);
	
	printf("\nPalavra: ");
	fflush(stdin);
	gets(palavra);
	
	linha=linha_da_palavra(nomeArq,palavra);
	
	if(linha!=NULL)
	printf("%2d", linha);
	
	
}
