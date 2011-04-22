#include <stdio.h>

int main() {
	long i, n;
	FILE *in = fopen("valsum.in", "r");
	FILE *o = fopen("valsum.out", "w");
	fscanf(in, "%ld", &n);
	for (i=4*8-1;i>=0;i--) {
		if((i+1) % 8==0 && i!=31) fprintf(o, " ");
		fprintf(o, "%ld",((n>>i)&1));
        }
	fprintf(o, "\n");
	for (i=3;i>=0;i--) {
                if(i!=3) fprintf(o, " ");
                fprintf(o, "%02lX",((n>>(i*8))&0xFF));
	}
	fprintf(o, "\n");
	fclose(in);
	fclose(o);
	return 0;
}
