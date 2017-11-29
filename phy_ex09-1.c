#include<stdio.h>

double real_product (double real1, double imag1, double real2, double imag2);
double imag_product (double real1, double imag1, double real2, double imag2);

int main(void)
{
/*Orismos metavliton*/
double x1, y1, x2, y2, x3, y3;

printf("Doste to pragmatiko meros tou protou migadikou arithmou: x1 = ");
scanf("%lf", &x1);
printf("Doste to fantastiko meros tou protou midadikou arithmou: y1 = ");
scanf("%lf", &y1);

printf("Doste to pragmatiko meros tou 2ou migadikou arithmou: x2 = ");
scanf("%lf", &x2);
printf("Doste to fantastiko meros tou 2ou migadikou arithmou: y2 = ");
scanf("%lf", y2);
x3 = real_product(x1,y1,x2,y2);
y3 = imag_product(x1,y1,x2,y2);
printf("\n z3 = %f + i%f\n", x3, y3);

return 0;
}

double real_product(double real1, double imag1, double real2, double imag2)
{
double temp = real1*real2 - imag1*imag2;
return temp;
}

double imag_product (double real1, double imag1, double real2, double imag2)
{
return real1*imag2 + imag1*real2;
}
