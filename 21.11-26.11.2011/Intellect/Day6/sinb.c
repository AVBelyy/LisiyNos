#include <stdio.h>

int main()
{
    int k, n;
    freopen("sinb.in", "r", stdin);
    freopen("sinb.out", "w", stdout);
    scanf("%d%d", &k, &n);
    if(n % k)
        printf("%d %d\n", n/k+1, n-k*(n/k));
    else
        printf("%d %d\n", n/k, k);
    return 0;
}
