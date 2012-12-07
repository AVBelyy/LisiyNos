#include <stdio.h>

int gcdex(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0; *y = 1;
		return b;
	}
	int x1, y1;
	int d = gcdex(b%a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return d;
}

int main() {
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
    int x, y, n, p;
    scanf("%d%d", &n, &p);
    if(n == 1) {
        printf("-1\n");
    } else {
        int g = gcdex (p, n, &x, &y);
        if (g != 1)
    	    printf("-1\n");
        else {
        	x = (x % n + n) % n;
    	    printf("%d\n", x);
        }
    }
    return 0;
}
