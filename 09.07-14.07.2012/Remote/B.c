#include <stdio.h>

int A[100][100], N;

int sum(int y, int x, int d) {
    int s = 0;

    do {
        s += A[y][x];
        y += 1;
        x += d;
    } while(y >= 0 && x >= 0 && y < N && x < N);

    return s;
}

int main() {
    int i, j;
    freopen("B.IN",  "r", stdin);
    freopen("B.OUT", "w", stdout);
    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // first sun line
    for(j = N - 1; j >= 0; j--) {
        printf("%d ", sum(0, j, 1));
    }

    for(i = 1; i < N; i++) {
        printf("%d ", sum(i, 0, 1));
    }

    printf("\n");

    // second sum line
    for(j = 0; j < N; j++) {
        printf("%d ", sum(0, j, -1));
    }

    for(i = 1; i < N; i++) {
        printf("%d ", sum(i, N - 1, -1));
    }

    printf("\n");
    return 0;
}