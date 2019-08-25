#include<stdio.h>
#include<conio2.h>
struct tppont
{
	char elem;
	tppont *prox,*antes;
};
tppont *inicia(tppont *lista)
{
	lista=NULL;
	return lista;
}
tppont *novacaixa(char elem)
{
	tppont *nc;
	nc=new tppont;
	nc->prox=NULL;
	nc->antes=NULL;
	nc->elem=elem;
	return nc;
}
tppont *insere(tppont *lista)
{
	tppont *caixa;
	printf("\nInsira elemento: ");
	char elem=getche();
	caixa=novacaixa(elem);
	
	if(lista==NULL)
	{
		caixa->prox=lista;
		lista=caixa;
	}
	else
	{
		caixa->prox=lista;
		caixa->prox->antes=caixa;
		lista=caixa;
	}
	return lista;
}
tppont *inseref(tppont *lista)
{
	tppont *caixa,*aux;
	char elem=getche();
	caixa=novacaixa(elem);
	if(lista==NULL)
	{
		caixa->prox=lista;
		lista=caixa;
	}
	else
	{
		aux=lista;
		while(aux->prox!=NULL)
		{
			aux=aux->prox;
		}
		aux->prox=caixa;
		caixa->antes=aux;
		
	}
	return lista;
}
tppont *inserentre(tppont *lista)
{
	tppont *caixa,*atual,*antes;
	char elem=getche();
	if(lista!=NULL)
	{
		char entre1,entre2;
		entre1=getche();
		atual=lista;
		antes=atual;
		while(atual!=NULL&&atual->elem!=entre1)
		{
			
			atual=atual->prox;
			antes=atual;
			
		}
		if(atual->elem==entre1&&atual!=NULL)
		{
			char entre2=getche();
			while(antes!=NULL&&antes->elem!=entre2)
			{
				antes=antes->prox;
			}
			if(antes->elem==entre2&&antes!=NULL&&entre1!=entre2)
			{
				caixa=novacaixa(elem);
				while(atual!=NULL&&atual->prox->elem!=entre2)
				atual=atual->prox;
				atual->prox=caixa;
				caixa->prox=antes;
				caixa->antes=atual;
				antes->antes=caixa;
			}
		}
	}
	return lista;	
}
tppont *insereorde(tppont *lista)
{
	tppont *caixa,*atual,*antes;
	char elem=getche();
	caixa=novacaixa(elem);
	if(lista==NULL)
	{
		caixa->prox=lista;
		lista=caixa;
	}
	else
	{
		atual=lista;
		antes=lista;
		while(atual!=NULL&&atual->elem<=elem)
		{
			antes=atual;
			atual=atual->prox;
		}
		if(atual==lista)
		{
			caixa->prox=lista;
			lista=caixa;
			caixa->prox->antes=caixa;
		}
		else
		{
			antes->prox=caixa;
			caixa->antes=antes;
			caixa->prox=atual;
			if(atual!=NULL)
			atual->antes=caixa;
		}
	}
	return lista;
}
tppont *retira(tppont *lista)
{
	tppont *aux,*antes;;
	char elem=getche();
	
  if(lista!=NULL)
  {
  	aux=lista;
  	while(aux!=NULL&&aux->elem!=elem)
	{
		antes=aux;
		aux=aux->prox;
	}
	if(aux->elem==elem)
	{
			if(aux==lista)
			{
				lista=aux->prox;
				lista->antes=NULL;
			}
			else
			{
				antes->prox=aux->prox;
				if(antes->prox!=NULL)
				antes->prox->antes=antes;
			}
			delete(aux);
	}
  }
	return lista;
}
void exibe(tppont *lista)
{
	if(lista==NULL)
	printf("\nLista nao existente");
	while(lista!=NULL)
	{
		printf("\n%c",lista->elem);
		lista=lista->prox;
	}
}
void exibeu(tppont *lista)
{
	if(lista==NULL)
	printf("\nLista nao existente");
	else
	{
		while(lista->prox!=NULL)
		lista=lista->prox;
		printf("\n%c",lista->elem);
	}
}
void exibep(tppont *lista)
{
	if(lista==NULL)
	printf("\nLista nao existente");
	else
	{
		printf("\n%c",lista->elem);
	}
}
int main(void)
{
	tppont *l;
	l=inicia(l);
	l=insere(l);
	l=insere(l);
	l=insere(l);
	l=insere(l);
	l=insere(l);
	exibe(l);
	l=inserentre(l);
	exibe(l);
}
