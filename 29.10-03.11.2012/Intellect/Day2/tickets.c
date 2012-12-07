#include <stdio.h>

int r[10];

int F[10100];

int main() {
    int n, i, j, k, flag;
    freopen("tickets.in", "r", stdin);
    freopen("tickets.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(i = 0; i < k; i++) {
        scanf("%d", &r[i]);
    }
    for(i = n-1; i >= 0; i--) {
        flag = 0;
        for(j = 0; j < k; j++) {
            if(!F[i+r[j]]) {
                flag = 1;
                break;
            }
        }
        F[i] = flag;
    }
    printf(F[0] ? "PETYA\n" : "MISHA\n");
    return 0;
}
