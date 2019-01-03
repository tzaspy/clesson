#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define PI             3.14159
#define R_CIRCLE       3.0

#define SQUARE_1_SIDE  2.0
#define SQUARE_1_X    -1.0
#define SQUARE_1_Y    -1.0

#define SQUARE_2_SIDE  1.0
#define SQUARE_2_X    -2.5
#define SQUARE_2_Y    -0.5

int main()
{

    int niter=0;
    double x,y;
    double d2, den;
    int is_in_circle;    // boolean to check if the point is in cirle
    int is_in_square_1;  // boolean to check if the point is in square 1 in the center
    int is_in_square_2;  // boolean to check if the point is in square 2
    double M, sm = 0.0;
    int n = 0;
    int i;
    double Sx=0.0, Sy=0.0, Sx2=0.0, Sy2=0.0, vm=0.0, ycm=0.0,xcm=0.0;;
    double mass, emass, excm, eycm;
    double area = pow( 6.0, 2);

    printf("Enter the number of iterations used to estimate mass: ");
    scanf("%d",&niter);

    /* initialize random numbers */
    srand(time(NULL));

    for ( i=0; i<niter; i++)
    {
        x = (double)((rand() % 6000) / 1000.0) - 3.0;
        y = (double)((rand() % 6000) / 1000.0) - 3.0;

        d2 = x*x + y*y;
        den = 1.0 + d2;
//        printf("x: %.2f, y: %.2f, d2: %.2f, dev: %.2f\n",x, y, d2, den);
        is_in_circle = 0;
        is_in_square_1 = 0;
        is_in_square_2 = 0;

    // Check if point in the circle
        if ( d2 <= pow(R_CIRCLE, 2))
        {
            is_in_circle = 1;
        }

        if (x >= SQUARE_1_X && x <= (SQUARE_1_X + SQUARE_1_SIDE) &&
                y >= SQUARE_1_Y && y <= (SQUARE_1_Y + SQUARE_1_SIDE) )
        {
            is_in_square_1 = 1;
        }

        if ( x >= SQUARE_2_X && x <= (SQUARE_2_X + SQUARE_2_SIDE) &&
                y >= SQUARE_2_Y && y <= (SQUARE_2_Y + SQUARE_2_SIDE) )
        {
            is_in_square_2 = 1;
        }

        if (is_in_circle && is_in_square_1 == 0  && is_in_square_2 == 0)
        {
            sm += den;
            Sx=Sx+x;
            Sy=Sy+y;
            Sx2=Sx2+x*x;
            Sy2=Sy2+y*y;
            vm+=den*den;
            n++;
        }

//        printf("x = %.3f, y = %.3f\n", x, y); 
    }

    mass = area * sm / niter;
    xcm=Sx/n; ycm=Sy/n;
    emass=area*sqrt((vm/niter-sm/niter*sm/niter)/niter);
    excm=area*sqrt(((Sx2/n)-(Sx*Sx)/(n*n))/n);
    eycm=area*sqrt(((Sy2/n)-(Sy*Sy)/(n*n))/n);
    printf ("\nside1: %.2f, side2: %.2f\n",SQUARE_1_SIDE, SQUARE_2_SIDE);
    printf("# of trials= %d , estimate of mass is %.6lf\n", niter, mass);
    printf("Mass=%f +- %f\n",mass,emass);
    printf("Xcm=%f +- %f\n",xcm,excm);
    printf("Ycm=%f +- %f\n\n",ycm,eycm);

/*  
    char pause;
    getchar();
    scanf("%c", &pause);
*/
    return 0;
}
