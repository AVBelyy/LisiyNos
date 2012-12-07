#include <stdio.h>
#include <math.h>

int main() {
    double a, p, q, u, v;
    double x0, y0;
    double denominator;
    // GEOMIWE EBANOE
    freopen("crane.in", "r", stdin);
    freopen("crane.out", "w", stdout);
    scanf("%lf%lf%lf%lf%lf", &a, &p, &q, &u, &v);
    denominator = v/u-(q-p)/a;
    // check if parallel
    x0 = denominator ? p/denominator : a;
    y0 = x0*v/u;
    printf("%.9lf\n", fabs(a/x0*sqrt(x0*x0+y0*y0)));
    return 0;
}
