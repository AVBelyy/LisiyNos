#include <stdio.h>
#include <math.h>

#define NMAX 250

double INF = 1E9;

double C[NMAX][2];
double cost[NMAX][NMAX];
int N;

int main() {
    int M, k, i, j, K;
    freopen("H.IN",  "r", stdin);
    freopen("H.OUT", "w", stdout);
    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            cost[i][j] = (i == j) ? 0 : INF;
        }
    }

    for(i = 0; i < N; i++) {
        double x1, y1, x2, y2;
        scanf("%Lf%Lf%Lf%Lf", &x1, &y1, &x2, &y2);
        C[i][0] = (x1 + x2) * .5;
        C[i][1] = (y1 + y2) * .5;
    }

    scanf("%d", &M);

    for(i = 0; i < M; i++) {
        int c1, c2;
        double d;
        scanf("%d%d", &c1, &c2);
        c1--;
        c2--;
        d = sqrt(pow(C[c1][0] - C[c2][0], 2) + pow(C[c1][1] - C[c2][1], 2));
        cost[c1][c2] = cost[c2][c1] = d;
    }

    // Floyd algorithm
    for(k = 0; k < N; k++) {
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                if (cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    scanf("%d", &K);

    for(i = 0; i < K; i++) {
        int F, T;
        scanf("%d%d", &F, &T);

        if(cost[F - 1][T - 1] - INF < 0.01 && cost[F - 1][T - 1] - INF > -0.01) {
            printf("Impossible\n");
        } else {
            printf("%.3f\n", cost[F - 1][T - 1]);
        }
    }

    return 0;
}