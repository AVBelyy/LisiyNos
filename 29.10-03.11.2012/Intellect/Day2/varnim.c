#include <stdio.h>

int a[100];

int main() {
    int n, i, j, t, T;
    freopen("varnim.in", "r", stdin);
    freopen("varnim.out", "w", stdout);
    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        scanf("%d", &n);
        T = 0;
        for(j = 0; j < n; j++) {
            scanf("%d", &a[j]);
            T += 2*a[j]-1;
        }
        printf((T % 2) ? "FIRST\n" : "SECOND\n");
    }
    return 0;
}
