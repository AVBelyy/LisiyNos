#include <stdio.h>
 
int roads[50000];
 
int main() {
    int n, i, m;
    freopen("railroad.in", "r", stdin);
    freopen("railroad.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        from--; to--;
        roads[from]++;
        roads[to]++;
    }
    for(i = 0; i < n; i++) {
        if(roads[i] == 1) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    for(i = 0; i < m; i++) {
        printf("%d\n", i+1);
    }
    return 0;
}
