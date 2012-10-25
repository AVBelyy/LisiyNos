#include <stdio.h>

int s1[201], s2[201];

int main() {
    int N, mid, i, j;
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &N);
    mid = (2*N-1)/2;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            int x;
            scanf("%d", &x);
            s1[mid-i+j] += x;
            s2[i+j] += x;
        }
    }
    for(i = 2*N-2; i >= 0; i--) {
        printf("%d ", s1[i]);
    }
    printf("\n");
    for(i = 0; i < 2*N-1; i++) {
        printf("%d ", s2[i]);
    }
    return 0;
}
