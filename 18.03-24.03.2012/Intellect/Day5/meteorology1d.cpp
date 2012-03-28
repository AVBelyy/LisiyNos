#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, a, b, c, d, e, cnt;
    int size[1000000];
    char cmd[8], moosor;
    memset(size, 0, sizeof(size));
    freopen("meteorology1d.in", "r", stdin);
    freopen("meteorology1d.out", "w", stdout);
    scanf("%d%d", &n, &m);// n - размер царства, m - кол-во событий
    for (int i=0; i<n; i++)
    {
        scanf("%s", cmd);
        if(!strcmp(cmd, "snow"))
        {
            scanf("%d%d%d", &a, &b, &c); //a - начало тучи, b - конец тучи, c - снегоемкость тучи
            for (int j=a; j<=b; j++) size[j]+=c;
        }
        else 
        {
            cnt = 0;
            scanf("%d%d", &d, &e);//d -начало суммирования, e - конец суммирования
            for(int j=d; j<=e; j++)
                cnt += size[j];
            printf("%d\n", cnt);
        }
    }
    return 0;
}
