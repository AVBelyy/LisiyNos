#include <stdlib.h>
#include <stdio.h>

int a[1001];

int main()
{
        int n, i, j, tmp;
        freopen("sort.in",  "r", stdin);
        freopen("sort.out", "w", stdout);
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            ++a[tmp];
        }
        for(i = 1; i < 1001; i++)
            for(j = 0; j < a[i]; j++)
                printf("%d ", i);
        printf("\n");
        return 0;
}
