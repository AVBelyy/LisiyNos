#include <stdio.h>
#include <string.h>

int r[10000][1000];
int Fs = 1;

int main()
{
    int F, j, l, i, n, c, x, f;
    freopen("lego.in", "r", stdin);
    freopen("lego.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        F = 0;
        scanf("%d%d", &l, &x);
        for(;;)
        {
            f = 0;
            for(j = x-1; j < x+l-1; j++)
            {
                if(r[F][j])
                {
                    f = 1;
                    break;
                }
            }
            if(!f)
            {
                memset(&r[F][x-1], 1, sizeof(int)*l);
                break;
            }
            if(++F >= Fs)
                // make new floor
                memset(r[Fs++], 0, sizeof(int)*1000);
        }
    }
    printf("%d\n", Fs);
    return 0;
}
