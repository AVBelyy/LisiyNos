#include <stdio.h>
#include <stdint.h>

int main() {
	int i;
	uint64_t n;
	uint64_t *ptr;
	FILE *in = fopen("binint.in", "r");
	FILE *o = fopen("binint.out", "w");
	fscanf(in, "%ld", &n);
	fclose(in);
	ptr = &n;
	for (i=4*8-1;i>=0;i--) {
                if((i+1) % 8==0 && i!=31) fprintf(o, " ");
                fprintf(o, "%ld",((*ptr>>i)&1));
        }
        fprintf(o, "\n");
        for (i=3;i>=0;i--) {
                if(i!=3) fprintf(o, " ");
                fprintf(o, "%02lX",((*ptr>>(i*8))&0xFF));
        }
	fprintf(o, "\n");
	fclose(o);
	return 0;
}
