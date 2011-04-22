#include <stdio.h>

int main() {
	long c;
	FILE *i = fopen("apbtest.in", "r");
	FILE *o = fopen("apbtest.out", "w");
	fscanf(i, "%ld", &c);
	fclose(i);
	fprintf(o, "%ld %ld\n", c/2, c-(c/2));
	fclose(o);
	return 0;
}
