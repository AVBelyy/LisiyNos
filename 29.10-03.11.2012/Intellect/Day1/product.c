#include <stdio.h>

int A[100][100], B[100][100];
int p, q, r;

int E(int y, int x) {
    int i, j, s = 0;
    for(i = 0; i < q; i++) {
        s += A[y][i]*B[i][x];
    }
    return s;
}

int main() {
    int i, j;
    freopen("product.in", "r", stdin);
    freopen("product.out", "w", stdout);
    scanf("%d%d%d", &p, &q, &r);
    for(i = 0; i < p; i++) {
        for(j = 0; j < q; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for(i = 0; i < q; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for(i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            printf("%d ", E(i, j));
        }
        printf("\n");
    }
    return 0;
}
