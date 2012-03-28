#include <stdio.h>

int main()
{
    int n, i, res, temp;
    freopen("excess.in", "r", stdin);
    freopen("excess.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        res ^= temp;
    }
    printf("%d\n", res);
    return 0;
}
