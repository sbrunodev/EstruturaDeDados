#include <stdio.h>
#include <conio2.h>

int Calcule (int x, int y)
{	
	
	if (y==1)
		return x;
	else
		return  x * Calcule (x,y-1); 
}

int main ()
{
	int x=0,y=0;
	printf ("Informe x: ");	
	scanf ("%d",&x);
	
	printf ("Informe y: ");	
	scanf ("%d",&y);
	
	printf ("\n %d^%d: %d",x,y, Calcule(x,y));
	getch ();
	
}
