#include <stdio.h>
#include <string.h>

char w[200001][51];
int  l[200001];
char t[51];

int main()
{
    int m, i, n, ch, l_ = 0, L = 0, j, flag, count, T;
    freopen("sufpref.in",  "r", stdin);
    freopen("sufpref.out", "w", stdout);
    scanf("%d\n", &n);
    i = n;
    while(i)
    {
        ch = getchar();
        if(ch == '\n')
        {
            l[i--] = L;
            L = 0;
        }
        else
            w[i][L++] = ch;
    }
    scanf("%d\n", &m);
    while(m)
    {
        ch = getchar();
        if(ch == '\n' || ch < 0)
        {
            --m;
            count = 0;
            for(i = 1; i <= n; i++)
            {
                flag = 1;
                T = l[i] - l_;
                if(T >= 0)
                {
                    for(j = 0; j < l_; j++)
                    {
                        if((w[i][j] != t[j]) || (w[i][j+T] != t[j]))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) ++count;
                }
                else
                    flag = 0;
            }
            printf("%d\n", count);
            l_ = 0;
        } else
            t[l_++] = ch;
    }
    return 0;
}