#include <stdio.h>
#include <conio2.h>

/*
10.	Construa uma fun��o que calcule a multiplica��o de dois n�meros positivos, 
    maiores que zero, atrav�s de sucessivas somas do primeiro n�mero. 
    Ex:
    2*10 = 20; 10+10 = 20;
*/
int Multiplicacao (int x, int y) 
{		
	if (x==1)
		return y;	
	else
		return Multiplicacao ((x-1),(y+y));
				
}

int main ()
{
	int x=0,y=0;
	printf ("x: ");	scanf ("%d",&x);
	printf ("y: ");	scanf ("%d",&y);
	
	printf (" %d*%d = %d",x,y,Multiplicacao(x,y));

	getch ();	
}
