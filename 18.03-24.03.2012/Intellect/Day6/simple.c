#include <stdio.h>
#include <string.h>

int is[10000001];

int main()
{
    int i, j, m, n;
    freopen("simple.in", "r", stdin);
    freopen("simple.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(is, 1, sizeof(is));
    is[1] = 0;
    for(i = 2; i*i <= m; i++)
        if(is[i])
            for(j = i*i; j <= m; j += i)
                is[j] = 0;
    for(i = n; i <= m; i++)
        if(is[i])
            printf("%d ", i);
    return 0;
}
