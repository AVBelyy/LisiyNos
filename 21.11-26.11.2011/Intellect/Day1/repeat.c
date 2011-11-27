#include <stdio.h>

int main()
{
        int i, N, res, tmp;
        freopen("repeat.in",  "r", stdin);
        freopen("repeat.out", "w", stdout);
        while(1)
        {
                scanf("%d", &N);
                if(!N) break;
                res = 0;
                for(i = 0; i < N; i++)
                {
                        scanf("%d", &tmp);
                        res ^= tmp;
                }
                printf("%d\n", res);
        }
        return 0;
}
