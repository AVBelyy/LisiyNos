#include <stdio.h>

#define max(A, B)   (((A) > (B)) ? (A) : (B))

#define CNT_MAX     2

typedef struct {
    int y;
    int x;
} Point;

Point p[CNT_MAX];

int main() {
    int m, n, i, j, cnt = 0;
    int S = 0;
    freopen("garnett.in", "r", stdin);
    freopen("garnett.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            int tmp;
            scanf("%d", &tmp);
            if(tmp) {
                p[cnt].y = i;
                p[cnt].x = j;
                cnt++;
            }
        }
    }
    for(i = 0; i < cnt; i++) {
        S = max(S, max(max(n*p[i].x, m*p[i].y), max(n*(m-p[i].x-1), m*(n-p[i].y-1))));
    }
    printf("%d\n", S);
    return 0;
}
