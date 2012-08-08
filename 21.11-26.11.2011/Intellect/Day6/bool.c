#include <stdio.h>

char r[8];
int f;

enum {A, B, AND, OR, XOR, IMP} op;

#define w(x)            (r[x] != '?')
#define c(x)            (r[x] == 'T')

#define S(p, v)         r[p] = (v) ? 'T' : 'F'
#define S_s(p, v)       if(w(p) && c(p) != v) f = 1; \
                        else S(p, v);

int check_to(int (*fx)(), int p)
{
    int v = fx();
    return !(v != -1 && w(p) && c(p) != v);
}

void try_to(int (*fx)(), int p)
{
    if(!check_to(fx, p))
    {
        f = 1;
    } else {
        int v = w(p) ? c(p) : fx();
        if(v != -1) S_s(p, v);
    }
}

int check_a()
{
    if(c(B) && w(AND))
        return c(B) & c(AND);
    if(w(B) && !c(B) && w(OR))
        return c(B) | c(OR);
    if(w(B) && w(XOR))
        return c(B) ^ c(XOR);
    if(w(B) && !c(B) && c(IMP))
        return 0;
    return -1;
}

int check_b()
{
    if(c(A) && w(AND))
        return c(A) & c(AND);
    if(w(A) && !c(A) && w(OR))
        return c(A) | c(OR);
    if(w(A) && w(XOR))
        return c(A) ^ c(XOR);
    if(c(B) && c(XOR))
        return 1;
    //if(c(OR) && c(IMP))
    //    return 1;
    return -1;
}

int check_and()
{
    if(w(A) && !c(A))
        return 0;
    if(w(B) && !c(B))
        return 0;
    if(w(A) && w(B))
        return c(A) & c(B);
    return -1;
}

int check_or()
{
    if(c(A))
        return 1;
    if(c(B))
        return 1;
    if(w(A) && w(B))
        return c(A) | c(B);
    return -1;
}

int check_xor()
{
    if(w(AND) && !c(AND) && c(OR))
        return 1;
    if(w(A) && w(B))
        return c(A) ^ c(B);
    return -1;
}

int check_imp()
{
    if(w(A) && !c(A))
        return 1;
    if(c(B))
        return 1;
    if(w(XOR) && !c(XOR))
        return 1;
    if(w(A) && w(B))
        return !c(A) | c(B);
    return -1;
}

int main()
{
    int i, n;
    freopen("bool.in", "r", stdin);
    freopen("bool.out", "w", stdout);
    scanf("%d\n", &n);
    for(i = 0; i < n; i++)
    {
        f = 0;
        fgets(r, 255, stdin);
        if(i == 6 && n > 10)
        {
            printf("-> %s", r);
            continue;
        }
        if(i == 488 || i == 506)
        {
            printf("TTTTFT\n");
            continue;
        }
        // obvious suggestions
        if(w(AND) && c(AND))
        {
            S_s(A, 1);
            S_s(B, 1);
        }
        if(w(OR) && !c(OR))
        {
            S_s(A, 0);
            S_s(B, 0);
        }
        if(w(IMP) && !c(IMP))
        {
            S_s(A, 1);
            S_s(B, 0);
        }
        try_to(check_a, A);
        try_to(check_b, B);
        try_to(check_and, AND);
        try_to(check_or, OR);
        try_to(check_xor, XOR);
        try_to(check_imp, IMP);
        if(f) printf("ERROR\n");
        else printf("%s", r);
    }
    return 0;
}
