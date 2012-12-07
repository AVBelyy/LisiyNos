#include <stdio.h>

int fastlog2(int x) {
    int res = 0;
    while(x) {
        x /= 2;
        res++;
    }
    return res;
}

int main() {
    int a, i, prev = 0;
    freopen("bubbles.in", "r", stdin);
    freopen("bubbles.out", "w", stdout);
    scanf("%d", &a);
    printf("%d %d\n", a*2-1, fastlog2(a*2-1));
    return 0;
}
