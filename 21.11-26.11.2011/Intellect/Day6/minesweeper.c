#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char f[202][202];

int main()
{
    int n, i, j, m, k;
    int x, y, dx, dy;
    char px;
    freopen("minesweeper.in",  "r", stdin);
    freopen("minesweeper.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    memset(f, 0, sizeof(f));
    for(i = 0; i < k; i++)
    {
        scanf("%d%d", &x, &y);
        f[x][y] = '*';
    }
    // rendering and output
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            px = '0';
            if(f[i][j] == '*')
            {
                putchar('*');
                continue;
            }
            for(dy = -1; dy <= 1; dy++)
                for(dx = -1; dx <= 1; dx++)
                    if(f[i+dy][j+dx] == '*')
                        px++;
            putchar(px == '0' ? '.' : px);
        }
        printf("\n");
    }
    return 0;
}
