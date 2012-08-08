#include <stdio.h>

int main()
{
    int k, i;
    freopen("issimple.in", "r", stdin);
    freopen("issimple.out", "w", stdout);
    scanf("%d", &k);
    for(i = 2; i < k; i++)
    {
        if(k % i == 0)
        {
            printf("NO,%d\n", i);
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
