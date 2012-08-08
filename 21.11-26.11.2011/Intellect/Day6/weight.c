#include <stdio.h>
#include <math.h>

int w[10];
int n;

int calc(int bm)
{
    int i = 0, res = 0;
    while(bm > 0)
    {
        if(bm & 1) res += w[i];
        bm >>= 1;
        i++;
    }
    return res;
}

void draw_bm(int bm)
{
    int i = 0;
    if(bm == 0)
    {
        printf("0\n");
    } else {
        while(bm > 0)
        {
            if(bm & 1) printf("%d ", w[i]);
            bm >>= 1;
            i++;
        }
        printf("\n");
    }
}

int main()
{
    int k, i, bm1, bm2, k1, k2, f;
    freopen("weight.in", "r", stdin);
    freopen("weight.out", "w", stdout);
    scanf("%d%d", &k, &n);
    for(i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for(bm1 = 0; bm1 < pow(2, n); bm1++)
    {
        for(bm2 = 0; bm2 < pow(2, n); bm2++)
        {
            f = 0;
            if(calc(bm1)+k == calc(bm2))
            {
                // check bitmasks
                k1 = bm1; k2 = bm2;
                for(i = 0; i < n; i++)
                {
                    if((k1 & 1) && (k2 & 1))
                    {
                        f = 1;
                        break;
                    }
                    k1 >>= 1; k2 >>= 1;
                }
                if(!f)
                {
                    f = 100500;
                    goto teh_end;
                }
            }
        }
    }
teh_end:
    if(f == 100500)
    {
        draw_bm(bm1);
        draw_bm(bm2);
    } else {
        printf("-1\n");
    }
    return 0;
}
