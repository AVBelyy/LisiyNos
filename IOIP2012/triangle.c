#include <stdio.h>
#include <string.h>

int T[200][200];

int N;

void cw(int y, int x) {
    int d = 0;
    while(x >= 0) {
        printf("%d ", T[y][x]);
        x--;
        if(d) y--;
        d = !d;
    }
    printf("\n");
}

void ccw(int y, int x) {
    int d = 0;
    while(y < N && x <= 2*y) {
        printf("%d ", T[y][x]);
        if(d) {
            x--;
        } else {
            x++; y++;
        }
        d = !d;
    }
    printf("\n");
}

int main() {
    int i, j;
    char dir[18];
    freopen("triangle.in",  "r", stdin);
    freopen("triangle.out", "w", stdout);
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        for(j = 0; j < 2*i+1; j++) {
            scanf("%d", &T[i][j]);
        }
    }
    scanf("%s", dir);
    if(!strcmp(dir, "clockwise")) {
        for(i = 0; i < 2*(N-1)+1; i += 2) {
            cw(N-1, i);
        }
    } else {
        for(i = N-1; i >= 0; i--) {
            ccw(i, 2*i);
        }
    }
    return 0;
}
