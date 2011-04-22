#include <stdio.h>
#include <stdint.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)

const unsigned long Inf = 4294967295U / 2;

int main() {
	long A[100][100];
	int next, x, y, i, n, m;
	unsigned long a, b, c;
	unsigned long l, M;
	bool B[100];
	unsigned long w[100];
	for(x = 0; x < 100; x++) {
		B[x] = false;
		w[x] = Inf;
		for(y = 0; y < 100; y++)
			A[x][y] = Inf;
	}
	FILE *fi = fopen("distance.in", "r");
	FILE *fo = fopen("distance.out", "w");
	fscanf(fi, "%d %d\n", &n, &m);
	for(i = 0; i < m; i++)
	{
		fscanf(fi, "%ld %ld %ld\n", &a, &b, &c);
		A[a-1][b-1] = min(A[a-1][b-1], c);
        	A[b-1][a-1] = min(A[a-1][b-1], c);
	}
	fscanf(fi, "%d %d", &x, &y);
    	x--;
    	y--;
	fclose(fi);
	if(x == y)
	{
		fprintf(fo, "0\n");
		fclose(fo);
		return 0;
	}
	l = x;
	w[x] = 0;
	do {
		B[l] = true;
		M = Inf;
		for(i = 0; i < n; i++) {
			if(!B[i]) {
                w[i] = min(w[i], w[l] + A[l][i]);
    			if(w[i] < M) { 
                    M = w[i]; next = i;
                }
            }
		}
		l = next;
	} while(M != Inf);
	fprintf(fo, "%ld\n", (w[y] == Inf) ? (-1): w[y]);
	fclose(fo);
	return 0;
}
