#include <stdio.h>

int main() {
    int k, C = 97;
    freopen("D.IN",  "r", stdin);
    freopen("D.OUT", "w", stdout);
    scanf("%d", &k);

    while(k % 2 == 0) {
        k /= 2;
        C++;
    }

    printf("%c\n", C);
    return 0;
}
