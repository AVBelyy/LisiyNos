#include <stdio.h>

int F[48];

int Fib(n) {
    int i;
    F[0] = 0;
    F[1] = 1;
    for(i = 2; i <= n; i++) {
        F[i] = F[i-1]+F[i-2];
    }
    return F[n];
}

int main() {
    int n;
    freopen("badsubs.in", "r", stdin);
    freopen("badsubs.out", "w", stdout);
    scanf("%d", &n);
    printf("%d\n", Fib(2*n+2));
    return 0;
}
