#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *a, *b, *B;

int main()
{
    int l, i = 0;
    a = malloc(11111);
    b = malloc(22222);
    B = b;
    freopen("strings.in", "r", stdin);
    freopen("strings.out", "w", stdout);
    fgets(a, 11111, stdin);
    fgets(b, 11111, stdin);
    l = strlen(a)-1;
    a[l] = '\0';
    b[l] = '\0';
    for(;;)
    {
        if(!strcmp(a, b)) break;
        if(i == l)
        {
            i = -1;
            break;
        }
        i++;
        *(b+l) = *b++;
        *(b+l) = '\0';
    }
    printf("%d\n", i);
    free(a);
    free(B);
    return 0;
}
