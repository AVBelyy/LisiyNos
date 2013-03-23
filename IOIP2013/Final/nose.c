#include <stdio.h>
 
int f[1000][1000];
 
int main() {
    int n, i, j, m;
    long long cnt = 0;
    freopen("nose.in", "r", stdin);
    freopen("nose.out", "w", stdout);
    scanf("%d%d ", &n, &m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%c", &f[i][j]);
        }
        scanf("%*c");
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(j+1 < m && f[i][j] == '.' && f[i][j+1] == '.') cnt++;
            if(i+1 < n && f[i][j] == '.' && f[i+1][j] == '.') cnt++;            
        }
    }
    printf("%I64d\n", cnt);
    return 0;
}
