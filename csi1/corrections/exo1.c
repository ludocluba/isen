#include <stdio.h>
#include <stdlib.h>

/* Exemple 1 */
int main(void)
{

	int a = 1;
    int b = 1;
	int c = 32;
	int d = 4;

	a = b++;
	printf("a=%d, b=%d, c=%d, d=%d\n", a,b,c,d);
    b = c / 32 - b;
	printf("a=%d, b=%d, c=%d, d=%d\n", a,b,c,d);
	a = (c-a)%d;
	printf("a=%d, b=%d, c=%d, d=%d\n", a,b,c,d);
    b = a + (a = 3);
	printf("a=%d, b=%d, c=%d, d=%d\n", a,b,c,d);
}
