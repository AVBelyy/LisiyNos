#include <stdio.h>

int main()
{
    int n, i, r, t;
    freopen("xorr.in", "r", stdin);
    freopen("xorr.out", "w", stdout);
    for(;;)
    {
        scanf("%d", &n);
        if(!n) break;
        r = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &t);
            r ^= t;
        }
        printf("%d\n", r);
    }
    return 0;
}
