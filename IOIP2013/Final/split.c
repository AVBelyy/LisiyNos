#include <stdio.h>
 
typedef struct {
    int a;
    int b;
    int sum;
    int diff;
} Pair;
 
int A[200000];
Pair P[100000];
 
int compare_int(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
 
int compare_pair(const void *a, const void *b) {
    int diff = ((Pair*)a)->diff - ((Pair*)b)->diff;
    if(diff == 0) {
        return ((Pair*)b)->sum - ((Pair*)a)->sum;
    } else {
        return diff;
    }
}
 
int main() {
    int n, i;
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < 2*n; i++) {
        scanf("%d", &A[i]);
    }
    qsort(A, 2*n, sizeof(int), compare_int);
    for(i = 0; i < n; i++) {
        P[i].a = A[2*i];
        P[i].b = A[2*i+1];
        P[i].sum  = P[i].b + P[i].a;
        P[i].diff = P[i].b - P[i].a;
    }
    qsort(P, n, sizeof(Pair), compare_pair);
    for(i = 0; i < n; i++) {
        printf("%d ", P[i].b);
    }
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("%d ", P[i].a);
    }
    printf("\n");
    return 0;
}
