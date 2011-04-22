#include <stdio.h>
#include <stdint.h>

int main() {
	int i;
	float n, p, q;
	uint32_t *ptr;
	FILE *in = fopen("binflt32.in", "r");
	FILE *o = fopen("binflt32.out", "w");
	fscanf(in, "%f %f", &p, &q);
	fclose(in);
	n = p/q;
	ptr = reinterpret_cast<uint32_t*>(&n);
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
