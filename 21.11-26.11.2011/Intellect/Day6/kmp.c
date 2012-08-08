#include <stdio.h>
#include <string.h>
#include <malloc.h>

int T[50005], S_l, W_l;

void kmp_table(char *W)
{
    int pos = 2, cnd = 0;
    T[0] = -1;  T[1] = 0;
    while(pos < W_l)
        if(W[pos-1] == W[cnd])
            T[pos++] = ++cnd;
        else if(cnd > 0)
            cnd = T[cnd];
        else
            T[pos++] = 0;
}

int kmp(char *S, char *W)
{
    int m = 0, i = 0;
    while(m+i < S_l)
    {
        if(W[i] == S[m+i])
        {
            if(i++ == W_l-1)
                return m;
        } else {
            m += i - T[i];
            i = (T[i] > -1) ? T[i] : 0;
        }
    }
    return -1;
}

int main()
{
    char ch, F = 1;
    int i, d = 0;
    char *S = malloc(500005), *W = malloc(500005), *out = S;
    freopen("kmp.in", "r", stdin);
    freopen("kmp.out", "w", stdout);
    while(!feof(stdin))
        if((ch = getchar()) == '\n')
        {
            if(F)
            {
                *out = '\0';
                 out = W;
                 F = 0;
            }
        } else if(ch != EOF) {
            *out++ = ch;
        }
    *out = '\0';
    W_l = strlen(W); S_l = strlen(S);
    kmp_table(W);
    while((i = kmp(S+d, W)) != -1)
    {
        d += i+1;
        printf("%d ", d-1);
    }
    free(S);
    free(W);
    return 0;
}
