#include <stdio.h>
 
int A[200000];
 
int main() {
    int n, i, j, k;
    freopen("battle.in", "r", stdin);
    freopen("battle.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < k; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(A[j] > A[j+1]) {
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
