#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a;
    int b;

    printf("Entrer un 1er entier:\n");
    scanf("%d", &a);
    printf("Entrer un 2eme entier:\n");
    scanf("%d", &b);

    printf("\nDivision entiere: %d \n", a/b);
    printf("\nReste de la division: %d \n", a%b);
}
