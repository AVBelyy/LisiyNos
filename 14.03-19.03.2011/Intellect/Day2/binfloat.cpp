#include <stdio.h>
#include <stdint.h>

int main() {
	int i;
	double n, p, q;
	uint64_t *ptr;
	FILE *in = fopen("binfloat.in", "r");
	FILE *o = fopen("binfloat.out", "w");
	fscanf(in, "%lf %lf", &p, &q);
	fclose(in);
	n = p/q;
	ptr = reinterpret_cast<uint64_t*>(&n);
	for (i=8*8-1;i>=0;i--) {
                if((i+1) % 8==0 && i!=63) fprintf(o, " ");
                fprintf(o, "%ld",((*ptr>>i)&1));
        }
        fprintf(o, "\n");
        for (i=7;i>=0;i--) {
                if(i!=7) fprintf(o, " ");
                fprintf(o, "%02lX",((*ptr>>(i*8))&0xFF));
        }
	fprintf(o, "\n");
	fclose(o);
	return 0;
}
