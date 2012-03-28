#include <stdio.h>

int main()
{
    int a, b, c, d;
    freopen("internet.in", "r", stdin);
    freopen("internet.out", "w", stdout);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (d<b) printf("%d\n", a);
    else
    printf("%d\n", a+(d-b)*c);
    return 0;
}
