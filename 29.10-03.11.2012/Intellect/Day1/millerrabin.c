#include <stdio.h>

long long N, d, s = 0;

long long mult(long long a, long long b, long long m) {
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

long long powermod(long long a, long long x, long long m) {
    long long res = 1;
    while(x > 0) {
        if(x % 2) {
            res = mult(a, res, m);
        }
        a = mult(a, a, m);
        x /= 2;
    }
    return res;
}

int MillerRabin(a) {
    int r;
    long long k = powermod(a, d, N);
    if(k == 1) return 0;
    for(r = 0; r < s; r++) {
        long long power = (1<<r)*d;
        k = powermod(a, power, N);
        if(k == N-1) return 0;
    }
    return 1;
}

int main() {
    int i, flag = 1;
    int testers[] = {2,3,5,7,11,13,17,19};
    freopen("millerrabin.in", "r", stdin);
    freopen("millerrabin.out", "w", stdout);
    scanf("%lld", &N);
    if(N % 2 == 0 || N == 1) {
        printf("-1\n");
        return 0;
    }
    for(i = 0; i < sizeof(testers)/sizeof(int); i++) {
        if(testers[i] == N) {
            printf("0\n");
            return 0;
        }
    }
    d = N-1;
    while(d % 2 == 0) {
        d /= 2;
        s++;
    }
    for(i = 0; i < sizeof(testers)/sizeof(int); i++) {
        if(MillerRabin(testers[i])) {
            flag = 0;
            printf("%d\n", testers[i]);
            break;
        }
    }
    if(flag) {
        printf("0\n");
    }
    return 0;
}
