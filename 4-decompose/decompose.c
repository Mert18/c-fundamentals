#include <stdio.h>

void decompose(double, long *, double *);

int main(void) {
	long i;
	double d;

	decompose(3.14159, &i, &d);

	printf("After decomposing: \n");
	printf("int part: %d\n", i);
	printf("double part: %f\n", d);
}

void decompose(double x, long *int_part, double *frac_part) {
	*int_part = (long) x;
	*frac_part = x - *int_part;
}
