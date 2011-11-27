#include <stdlib.h>
#include <stdio.h>

typedef int big_array[1000000];
big_array a[3];

int compare(void *a, void *b)
{
    return (*(big_array*)a[2]-*(big_array*)b[2]);
}

int main()
{
    int n, i, m;
    freopen("tree.in",  "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++)
       scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    qsort(a, m, sizeof(int)*3, compare);
    for(i = 0; i < m; i++)
        printf("%d %d %d\n", &a[i][0], &a[i][1], &a[i][2]);
    return 0;
}
