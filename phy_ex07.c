#include <stdio.h>

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
	int a[m][n];
	int b[n][p];
	int c[m][p];

	// Read elements of matrix A
	printf ("\nGive elements of B");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf("\nA[%d][%d] = ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}


	// Read elements of matrix B
	printf ("\nGive elements of B");
	for (i=0; i<n; i++) {
		for (j=0; j<p; j++) {
			printf("\nB[%d][%d] = ", i+1, j+1);
			scanf("%d", &b[i][j]);
		}
	}

	// multiply AxB, element by element
	for (i=0; i<m; i++) {
		for (j=0; j<p; j++) {
			int temp = 0;
			for (int k=0; k<n; k++) {
				temp += a[i][k] * b[k][j];
			}
			c[i][j] = temp;
			printf ("\n C[%d][%d] = %d\n", i+1, j+1, c[i][j]);
		}
	}

	return 0;

}