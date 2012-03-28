#include <stdio.h>

int n, m;
int p[16];
int h2[16];
int Pow[1<<16];

int power(int bm)
{
    int i, res = 1;
    for(i = 0; bm; bm >>= 1, i++)
        if(bm & 1)
            res *= p[i];
    return res;
}

int main()
{
    int i, cur, bm, bm2, c2, j;
    int max = 0, max2 = 0;
    int jj, jj2;
    freopen("crystals.in", "r", stdin);
    freopen("crystals.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    if(n == 2)
    {
        printf("%d\n", p[0]+p[1]);
        return 0;
    }
    for(i = 0; i < (1<<n); i++)
        Pow[i] = power(i) % m;

    for(i = 1; i < (1<<n); i++)
    {
        for(j = 0; j <= i; j++)
        {
            jj = i & j;
            jj2 = i - jj;
            if(max < Pow[jj] + Pow[jj2])
               max = Pow[jj] + Pow[jj2];
        }
    }
    printf("%d\n", max);
    return 0;
}
