#include <stdio.h>

typedef long long matrix[2][2];

matrix a;
long long n, m;

long long prod(long long a, long long b, long long m) {
    long long res = 0;
    while(b > 0) {
        if(b % 2) {
            res = (a+res)%m;
        }
        a = (a+a)%m;
        b /= 2;
    }
    return res;
}

void mult(matrix b, matrix c) {
    int i, j, k;

    a[0][0] = 0;
    a[1][0] = 0;
    a[0][1] = 0;
    a[1][1] = 0;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++) {
                a[i][j] = (a[i][j] + prod(b[i][k], c[k][j], m)) % m; 
            }
        }
    }
}

int main() {
    int g, d;
    freopen("fibmod.in", "r", stdin);
    freopen("fibmod.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    matrix res = {{1, 1}, {1, 0}};      
    matrix x = {{1, 1}, {1, 0}};
    while (n > 0) {
        if (n % 2) {
            mult(res, x);
            for(g = 0; g < 2; g++)
                for(d = 0; d < 2; d++)
                    res[g][d] = a[g][d];
        }
        mult(x, x);
        for(g = 0; g < 2; g++)
            for(d = 0; d < 2; d++)
                x[g][d] = a[g][d];

        n = n / 2;
    }
    printf("%lld\n", res[1][1]);
    return 0;
}
