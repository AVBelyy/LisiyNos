#include <stdio.h>

int main() {
    int N, i;
    freopen("another.in", "r", stdin);
    freopen("another.out", "w", stdout);
    scanf("%d", &N);
    printf("%d\n", N/2);
    for(i = N/2-1; i >= 0; i--) {
        printf("%c %c\n", 'A'+i, 'A'+N-i-1);
    }
    return 0;
}
