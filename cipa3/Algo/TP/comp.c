#include <stdio.h>
#include <stdlib.h>

typedef struct comp complex;

struct comp {
    float re;
    float im;
};

complex addition (complex a, complex b); 
void affichage (complex a); 
void init (complex* a, float re, float im); 

int main() {

    complex a1 = {1.1,2.2};
    complex a2 = {3.3,4.4};
    complex c;
	
	c = addition(a1,a2);
	affichage(c);
	init(&c,10,20);
	affichage(c);
}

complex addition (complex a, complex b) {
    complex c;
	c.re=a.re+b.re;
	c.im=a.im+b.im;
	return c;
} 
void affichage (complex a) {
	printf("struct:\n\tre:%f\n\tim:%f\n", a.re, a.im);
}

void init (complex* a, float re, float im) {
    a->re = re;
	a->im = im;
}














