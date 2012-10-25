#include <stdio.h>
#include <string.h>

typedef struct {
    char c;
    int  owner;
    int  flag;
} p;

p F[22][22];

void clear_field() {
    int i, j;
    for(i = 0; i < 22; i++) {
        for(j = 0; j < 22; j++) {
            F[i][j].flag = 0;
        }
    }
}

void fill(int x, int y, int c) {
    if(x < 0 || y < 0 || x >= 22 || y >= 22 || F[x][y].flag) return;
    F[x][y].flag = 1;
    if(F[x][y].c == 'A'+c) return;
    fill(x  , y-1, c);
    fill(x+1, y  , c);
    fill(x,   y+1, c);
    fill(x-1, y  , c);
}

void check_field(int t) {
    int i, j;
    for(i = 1; i <= 20; i++) {
        for(j = 1; j <= 20; j++) {
            if(!F[i][j].flag) {
                char c = F[i][j].c;
                if(t == 0 && c == 'B') c = 'b';
                if(t == 0 && c == 'a') c = 'A';
                if(t == 0 && (c == '_' || c == ',' || c == '.')) c = '.';
                if(t == 1 && c == 'A') c = 'a';
                if(t == 1 && c == 'b') c = 'B';
                if(t == 1 && (c == '_' || c == ',' || c == '.')) c = ',';
                F[i][j].c = c;
            }
        }
    }
}

int main() {
    int N, i, j, x, y, as = 0, bs = 0;
    freopen("J.IN",  "r", stdin);
    freopen("J.OUT", "w", stdout);
    scanf("%d", &N);
    for(i = 1; i <= 20; i++) {
        for(j = 1; j <= 20; j++) {
            F[i][j].c = '_';
        }
    }
    j = 0;
    for(i = 0; i < N; i++) {
        scanf("%d%d", &y, &x);
        F[y][x].c = 'A'+j;
        F[y][x].owner = j;
        clear_field();
        fill(0, 0, j);
        check_field(j);
        j = !j;
    }
    for(i = 1; i <= 20; i++) {
        for(j = 1; j <= 20; j++) {
            printf("%c", F[i][j].c);
        }
        printf("\n");
    }
    for(i = 1; i <= 20; i++) {
        for(j = 1; j <= 20; j++) {
            switch(F[i][j].c) {
                case 'a': as++; break;
                case 'b': bs++; break;
            }
        }
    }
    printf("%d:%d\n", bs, as);
    return 0;
}
