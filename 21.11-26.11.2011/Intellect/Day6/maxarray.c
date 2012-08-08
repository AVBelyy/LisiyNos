#include <stdio.h>

int a[100][100];

int sum(int y1, int x1, int y2, int x2)
{
    int i, j, s = 0;
    for(i = y1; i <= y2; i++)
        for(j = x1; j <= x2; j++)
            s += a[i][j];
    return s;
}

int main()
{
    int n, i, j, p, q, T, max = -1005000000;
    int y1, x1, y2, x2;
    freopen("maxarray.in", "r", stdin);
    freopen("maxarray.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for(i = 0; i < n; i++) // y1
    {
        for(j = 0; j < n; j++) // x1
        {
            for(p = i; p < n; p++) // y2
            {
                for(q = j; q < n; q++) // x2
                {
                    T = sum(i, j, p, q);
                    if(max < T)
                    {
                        max = T;
                        y1 = i;
                        x1 = j;
                        y2 = p;
                        x2 = q;
                    }
                }
            }
        }
    }
    for(i = y1; i <= y2; i++)
    {
        for(j = x1; j <= x2; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
