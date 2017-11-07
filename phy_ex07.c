#include <stdio.h>

void read_array (char array_name, int m, int n, double array[m][n]) {
	int i, j;
	printf ("\nGive elements of %c", array_name);
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf("\n%c[%d][%d] = ", array_name, i+1, j+1);
			scanf("%lf", &array[i][j]);
		}
	}
}

int main(void) {

	int n, m, p;
	int i, j;

	printf("\n in this program we will multiply a MxN matrix A with an NxP matrix B");

	printf("\n Give number of rows of matrix A, M= ");
	scanf ("%d", &m);

	printf("\n Give number of columns of matrix A, N= ");
	scanf("%d", &n);

	printf("\n Give number of columns of matrix B, P= ");
	scanf("%d", &p);


	// Here we define the matrices A, B
	double a[m][n];
	double b[n][p];
	double c[m][p];

	// Read elements of matrix A
	read_array('A', m, n, a);


	// Read elements of matrix B
	read_array('B', n, p, b);

	// multiply AxB, element by element
	for (i=0; i<m; i++) {
		for (j=0; j<p; j++) {
			double temp = 0;
			for (int k=0; k<n; k++) {
				temp += a[i][k] * b[k][j];
			}
			c[i][j] = temp;
			printf ("\n C[%d][%d] = %lf\n", i+1, j+1, c[i][j]);
		}
	}

	return 0;

}

