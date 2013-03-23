#include <stdio.h>
#include <stdint.h>

uint64_t A[100000], P[100000];

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, i, j, t, q;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    qsort(A, n, sizeof(uint64_t), compare);
    P[0] = A[0];
    for(i = 1; i < n; i++) {
        P[i] = P[i-1] + A[i];
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        int k, t, last_j;
        long long res = 0;
        scanf("%d", &k);
        for(j = n-1, t = 1; j >= 0; j -= k, t++) {
            last_j = j;
            res += t*(P[j] - P[j-k]);
        }
        printf("%lld ", res-A[n-1]);
    }
    /*
    for(i = 0; i < q; i++) {
        int k, o;
        long long res = 0, prev = 0, cur;
        scanf("%d", &k);
        o = n % k;
        for(j = 0; j < o-1; j++) {
            res += A[j];
        }
        if(o) {
            prev = res + A[o-1];
        }
        for(j = 0; j < n/k; j++) {
            cur = 0;
            for(t = 0; t < k-1; t++) {
                cur += A[k*j+t+o];
            }
            res += cur + prev;
            prev = res + A[k*j+k-1+o];
        }
        printf("%I64d ", res);
    }*/
    printf("\n");
    return 0;
}
