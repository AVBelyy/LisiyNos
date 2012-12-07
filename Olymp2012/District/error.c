#include <stdio.h>

char addr[100][10];
int n;

int funktsiya(const char A[10]) {
    int raznitsa, kolichestvo = 0, i, j, resultat;
    for(i = 0; i < n; i++) {
        raznitsa = 0;
        for(j = 0; j < 10; j++) {
            if(A[j] != addr[i][j]) raznitsa++;
        }
        if(raznitsa <= 1) {
            kolichestvo++;
            resultat = i;
        }
    }
    if(kolichestvo == 0) return -1;
    if(kolichestvo == 1) return resultat;
    if(kolichestvo  > 1) return -2;
}

int main() {
    int m, i;
    char buf[10];
    freopen("error.in", "r", stdin);
    freopen("error.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s", addr[i]);
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%s", buf);
        int index = funktsiya(buf);
        if(index >= 0) {
            printf("%s\n", addr[index]);
        } else {
            printf("%d\n", index);
        }
    }
    return 0;
}
