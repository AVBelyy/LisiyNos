#include <stdio.h>
#include <math.h>

int main() {
    double n;
    int i, s;
    freopen("divider.in", "r", stdin);
    freopen("divider.out", "w", stdout);
    scanf("%lf", &n);
    s = floor(sqrt(n));
    printf("%d\n", (int)(n-s));
    for(i = s+1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
