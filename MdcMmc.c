#include <stdio.h>

typedef struct Pair2Segments 
{
	int a;
	int b;
}Segments;

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

// Função para calcular o MMC de dois números
int mmc(int a, int b) {
    int prod = 1; // Produto dos fatores primos
    int d = 2;    // Divisor inicial

    while (a != 1 || b != 1) {
        // Enquanto um dos números for divisível por `d`
        while (a % d == 0 || b % d == 0) {
            prod *= d; // Multiplica o produto pelo divisor
            if (a % d == 0)
                a /= d; // Reduz `a` dividindo por `d`
            if (b % d == 0)
                b /= d; // Reduz `b` dividindo por `d`
        }
        d++; // Incrementa o divisor
    }

    return prod; // Retorna o MMC
}

int main(int argc, char *argv[])
{
	// Exemplos de cálculo do MDC e MMC
	
	Segments segments[] = {{56,98},{48,18},{101,103},{36,60},{12,18},{15,20},{7,5},{21,6}};
   
	int n = sizeof(segments) / sizeof(segments[0]);

	for (int i = 0; i<n; i++)
		printf("O MDC de %d e %d eh %d\n", segments[i].a, segments[i].b, mdc(segments[i].a, segments[i].b));
	
	for (int i = 0; i<n; i++)
		printf("O MMC de %d e %d eh %d\n", segments[i].a, segments[i].b, mmc(segments[i].a, segments[i].b));
	// o produto de a e b deverah ser igual ao produto de mdc(a,b) e mmc(a,b)
	for (int i = 0; i<n; i++)
		if  ( (mdc(segments[i].a, segments[i].b)*mmc(segments[i].a, segments[i].b))==(segments[i].a*segments[i].b) )
			printf("\n O o MDC e MMC de %d e %d foram calculados corretamente \n", segments[i].a, segments[i].b);
		else
			printf("\n O o MDC e MMC de %d e %d foram calculados incorretamente \n", segments[i].a, segments[i].b);



	return 0;
}