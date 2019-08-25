#include <stdio.h>
#include <conio2.h>

float MDC (float x, float y)
{	
	if (y==y)
		return y;
	if (x<y)
		return MDC (y,x);
	if (x>y)
		return MDC (x-y,y);	
}

int main ()
{
	float x=0,y=0;
	printf ("Informe x: ");	
	scanf ("%f",&x);
	
	printf ("Informe y: ");	
	scanf ("%f",&y);
	
	printf ("\n MDC %2.f e%2.f:%2.f",x,y, MDC(x,y));
	getch ();	
}


