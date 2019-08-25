#include <stdio.h>
#include <conio2.h>

int MDC (int x, int y)
{	
	if (y==0)
		return x;
	else
		return  MDC (y,x%y); 
}

int main ()
{
	int x=0,y=0;
	printf ("Informe x: ");	
	scanf ("%d",&x);
	
	printf ("Informe y: ");	
	scanf ("%d",&y);
	
	printf ("\n MDC %d e %d: %d",x,y, MDC(x,y));
	getch ();	
}
