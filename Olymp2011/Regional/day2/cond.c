#include <stdio.h>
#include <string.h>

#define min(x, y)   ((x) < (y) ? (x) : (y))
#define max(x, y)   ((x) > (y) ? (x) : (y))

char mode[8];

int main()
{
    int t1, t2;
    freopen("cond.in",  "r", stdin);
    freopen("cond.out", "w", stdout);
    scanf("%d%d%s", &t1, &t2, mode);
    if(!strcmp(mode, "freeze"))
        printf("%d\n", min(t1, t2));
    if(!strcmp(mode, "heat"))
        printf("%d\n", max(t1, t2));
    if(!strcmp(mode, "auto"))
        printf("%d\n", t2);
    if(!strcmp(mode, "fan"))
        printf("%d\n", t1);
    return 0;
}