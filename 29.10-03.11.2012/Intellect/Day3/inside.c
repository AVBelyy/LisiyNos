#include <stdio.h>

float vx[100000], vy[100000];

int main() {
    int N, i, j, flag = 0;
    float x, y;
    freopen("inside.in", "r", stdin);
    freopen("inside.out", "w", stdout);
    scanf("%d%f%f", &N, &x, &y);
    for(i = 0; i < N; i++) {
        scanf("%f%f", &vx[i], &vy[i]);
    }
    for(i = 0, j =N-1; i < N; j = i++) {
        if(((vy[i]>y) != (vy[j]>y)) && (x < (vx[j]-vx[i])*(y-vy[i])/(vy[j]-vy[i])+vx[i]))
           flag = !flag;
    }
    printf(flag ? "YES\n": "NO\n");
    return 0;
}