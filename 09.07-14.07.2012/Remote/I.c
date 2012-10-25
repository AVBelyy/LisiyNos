#include <stdio.h>

int main() {
    int Q, i;
    freopen("I.IN",  "r", stdin);
    freopen("I.OUT", "w", stdout);
    scanf("%d", &Q);

    if(Q == 4) {
        printf("2101\n");
    } else if(Q == 5) {
        printf("12002\n");
    } else if(Q >= 7) {
        printf("21");

        for(i = 7; i < Q; i++) {
            printf("0");
        }

        printf("1000");

        if(Q - 4 < 10) {
            printf("%d\n", Q - 4);
        } else {
            printf("%c\n", 'A' + (Q - 14));
        }
    } else {
        printf("0\n");
    }

    return 0;
}