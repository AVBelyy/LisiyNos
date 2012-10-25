#include <stdio.h>
#include <string.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int R[100000];
long long int N, K;

int move(int k) {
    int p = N-k-1, l = R[N-1];
    memmove(&R[p+1], &R[p], k*sizeof(int));
    R[p] = l;
    return k;
}

int main() {
    int i;
    freopen("inverse.in",  "r", stdin);
    freopen("inverse.out", "w", stdout);
    scanf("%lld%lld", &N, &K);
    if(K > N*(N-1)/4) {
        K = N*(N-1)/2-K;
        for(i = 0; i < N; i++) {
            R[i] = N-i;
        }
    } else {
        for(i = 0; i < N; i++) {
            R[i] = i+1;
        }
    }
    for(i = 0; i < N-1, K; i++) {
        K -= move(min(N-i-1, K));
    }
    for(i = 0; i < N; i++) {
        printf("%d ", R[i]);
    }
    printf("\n");
    return 0;
}
