#include <stdio.h>

int main() {
	long i, n;
	FILE *in = fopen("binshort.in", "r");
	FILE *o = fopen("binshort.out", "w");
	fscanf(in, "%ld", &n);
	for (i=2*8-1;i>=0;i--) {
		if((i+1) % 8==0 && i!=15) fprintf(o, " ");
		fprintf(o, "%ld",((n>>i)&1));
        }
	fprintf(o, "\n");
	for (i=1;i>=0;i--) {
                if(i!=1) fprintf(o, " ");
                fprintf(o, "%02lX",((n>>(i*8))&0xFF));
	}
	fprintf(o, "\n");
	fclose(in);
	fclose(o);
	return 0;
}
