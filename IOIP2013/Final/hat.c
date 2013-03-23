#include <stdio.h>
#include <math.h>
 
long long f(long long n) {
    int cnt = 0;
    while(n) {
        if(n & 1) cnt++;
        n >>= 1;
    }
    return cnt;
}
 
int main() {
    int q, i;
    long long n, p;
    freopen("hat.in", "r", stdin);
    freopen("hat.out", "w", stdout);
    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        scanf("%I64d%I64d", &n, &p);
        printf("%I64d\n", f(n-1)%p);
    }
    return 0;
}
