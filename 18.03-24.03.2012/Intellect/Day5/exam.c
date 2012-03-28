#include <stdio.h>
#include <string.h>

int taken[100500];

int main()
{
    int n, i, p;

    memset(taken, 0, 100500*sizeof(int));

    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p);
        if(p < 0)
            taken[-p] = 0;
        else
        {
            for(; taken[p]; p++);
            taken[p] = 1;
            printf("%d\n", p);
        }
    }
    return 0;
}
