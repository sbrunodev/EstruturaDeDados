#include <stdio.h>

int numero (int num)
{
	printf ("%d \n",num);
	
	if (num==1)
		return 1;
	else
		return numero(num-1);
		
}

int main ()
{
	numero (5);
		
}
