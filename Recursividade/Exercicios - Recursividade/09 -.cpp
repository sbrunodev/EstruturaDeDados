#include <stdio.h>

int Mult (int x, int y, int Aux)
{
	if (x==1)
		return y;
	else
		return Mult (x-1,y+Aux,Aux);
}

int main ()
{
	int x,y;
	
	printf ("Informe x: "); scanf ("%d",&x);
	printf ("Informe y: "); scanf ("%d",&y);
	printf ("%d^%d : %d",x,y,Mult(x,y,y));
}
