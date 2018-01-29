#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

// Programme Aire et perimetre cercle
int main () {
    int r = 1;

    for (r=1; r<21; r++) {
        printf(" Perimetre : %f \n", 2*M_PI*r);
        printf(" Aire : %f \n", M_PI*M_PI*r);
    }

}
