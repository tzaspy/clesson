#include <stdio.h>

//Dilosi synartiseon:
//Edo i exodos einai typou int
int factorial(int n_int);
//Edo den yparhei exodos alla mia metabliti kaleitai me anafora (i n_factorial)
void calculate_factorial(int m_int, int *n_factorial);

int main(void)
{
	int n, m, k ;

	printf"(\nGive me non-negative value of N = ");
	scanf"(%d, &n);

	//O enas tropos:
	k = factorial(n);
	printf"(\n%d!=%"d,n,k);

	//O allos tropos:
	calculate_factorial(n,&m);
	printf"(\n%d!=%"d,n,m);

	return 0;
}

int factorial(int n_int);
{
	int i, fact; //i, fact einai topikes metablites

	if (n_int = = 0)
		return 1;
	else
	{
		fact = 1;
		for (i=1; i<=n_int; i++)
			fact *= i;
		return fact;
	}
}

void calculate_factorial(int m_int, int *n_factorial)
{
	int i, fact;
	if (m_int = = 0)
		*n_factorial = 1;
	else
	{
		fact = 1;
		for (i=1; i<=m_int; ++i)
			fact *= i;
		*n_factorial = fact;
	}
}
