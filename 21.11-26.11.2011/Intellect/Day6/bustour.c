#include <stdio.h>

int main()
{
    int t, i, n, f = 1;
    freopen("bustour.in",  "r", stdin);
    freopen("bustour.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if(t <= 437)
        {
            f = 0;
            printf("Crash %d\n", i+1);
            break;
        }
    }
    if(f) printf("No crash\n");
    return 0;
}
