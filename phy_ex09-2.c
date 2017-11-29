#include <stdio.h>

//Dilosi synartiseon:
//Edo i exodos einai typou int
unsigned long factorial(short n_int);
//Edo den yparhei exodos alla mia metabliti kaleitai me anafora (i n_factorial)
void calculate_factorial(short m_int, unsigned long *n_factorial);

int main(void)
{
	short n;
	unsigned long k, m;

	printf("Give me non-negative value of N (0-65) = ");
	scanf("%hu", &n);

	//O enas tropos:
	k = factorial(n);
	printf("- using factorial(n):\t\t\t%hu!=%lu\n", n, k);

	//O allos tropos:
	calculate_factorial(n, &m);
	printf("- using calculate_factorial(n, &m):\t%hu!=%lu\n", n, m);

	return 0;
}

unsigned long factorial(short n_int)
{
	int i; //i, fact einai topikes metablites
	unsigned long fact;
	if (n_int == 0)
		return 1;
	else
	{
		fact = 1;
		for (i=1; i<=n_int; i++)
			fact *= i;
		return fact;
	}
}

void calculate_factorial(short m_int, unsigned long *n_factorial)
{
	int i;
	unsigned long fact;
	if (m_int == 0)
		*n_factorial = 1;
	else
	{
		fact = 1;
		for (i=1; i<=m_int; ++i)
			fact *= i;
		*n_factorial = fact;
	}
}
