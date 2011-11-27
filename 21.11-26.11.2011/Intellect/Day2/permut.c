#include <stdio.h>
#include <stdlib.h>

int a[1000000];

int compare(void *a, void *b)
{
    return (*(int*)a-*(int*)b);
}

int main()
{
    int n, i;
    freopen("permut.in",  "r", stdin);
    freopen("permut.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
