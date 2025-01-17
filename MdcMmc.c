#include <stdio.h>

int mdc(int dividend , int divisor)
{
	int rest = dividend % divisor;
	
	while (rest != 0)
	{
		dividend = divisor;
		divisor = rest;
		rest = dividend % divisor;
		
	}
	return divisor;
}

int main(int argc, char *argv[])
{
	// Exemplos de cálculo do MDC
    int dividendo1 = 56, divisor1 = 98;
    int dividendo2 = 48, divisor2 = 18;
    int dividendo3 = 101, divisor3 = 103; // Números primos entre si
    int dividendo4 = 36, divisor4 = 60;

    printf("O MDC de %d e %d eh %d\n", dividendo1, divisor1, mdc(dividendo1, divisor1));
    printf("O MDC de %d e %d eh %d\n", dividendo2, divisor2, mdc(dividendo2, divisor2));
    printf("O MDC de %d e %d eh %d\n", dividendo3, divisor3, mdc(dividendo3, divisor3));
    printf("O MDC de %d e %d eh %d\n", dividendo4, divisor4, mdc(dividendo4, divisor4));

	return 0;
}