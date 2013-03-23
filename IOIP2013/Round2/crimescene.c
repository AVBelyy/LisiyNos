#include <stdio.h>
#include <math.h>

#define min(A, B)   (((A) < (B)) ? (A) : (B))
#define max(A, B)   (((A) > (B)) ? (A) : (B))

#define phi         10E-9

typedef struct {
    int y;
    int x;
} Point;

Point p[100000];
int a[100000];
int n, l, k;

double walk(int s, int d) {
    double L = l;
    double res = 0.0f;
    while(1) {
        int ss = ((s+d)%n+n)%n;
        double ll = sqrt(pow(p[s].y-p[ss].y, 2) + pow(p[s].x-p[ss].x, 2));
        L -= ll;
        if(L < phi) {
            if(a[d == 1 ? s : ((s-1)%n+n)%n]) res += L+ll;
            break;
        }
        if(a[d == 1 ? s : ((s-1)%n+n)%n]) res += ll;
        s = ss;
    }
    return res;
}

int main() {
    int i;
    double t = 0.0f;
    freopen("crimescene.in", "r", stdin);
    freopen("crimescene.out", "w", stdout);
    scanf("%d%d%d", &n, &l, &k);
    for(i = 0; i < k; i++) {
        int tmp;
        scanf("%d", &tmp);
        a[tmp-1] = 1;
    }
    for(i = 0; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    // calculate the perimeter
    double P = 0.0f;
    for(i = 0; i < n; i++) {
        int ii = (i+1)%n;
        double ll = sqrt(pow(p[i].y-p[ii].y, 2) + pow(p[i].x-p[ii].x, 2));
        if(a[i]) P += ll;
    }
    // calculate
    for(i = 0; i < n; i++) {
        t = max(t, max(walk(i, 1), walk(i, -1)));
    }
    printf("%lf\n", P-t);
    return 0;
}
