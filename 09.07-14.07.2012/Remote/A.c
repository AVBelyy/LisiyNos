#include <stdio.h>

int A[10000];

int main() {
    int N, d, j, o, t, vmax = 0, l, llmax;
    int lmax = 0, dmax, omax, nmax = 0, nvmax;
    freopen("A.IN",  "r", stdin);
    freopen("A.OUT", "w", stdout);
    scanf("%d", &N);
    for(d = 0; d < N; d++) {
        scanf("%d", &t);
        if(vmax < t) vmax = t;
        A[t-1]++;
    }
    for(d = 1; d < vmax; d++) {
        for(o = 0; o < d; o++) {
            l = 0; llmax = 0;
            for(j = o; j < vmax; j += d) {
                if(A[j]) {
                    l++;
                } else {
                    if(llmax < l) llmax = l;
                    l = 0;
                }
            }
            if(llmax < l) llmax = l;
            if(lmax < llmax) {
                lmax = llmax;
                dmax = d;
                omax = o;
            }
        }
    }
    for(j = 0; j < vmax; j++) {
        if(nmax < A[j]) {
            nmax = A[j];
            nvmax = j+1;
        }
    }
    if(nmax < lmax) {
        printf("%d\n", lmax);
        for(j = 0, t = omax; j < lmax; j++, t += dmax) {
            printf("%d ", t+1);
        }
    } else {
        printf("%d\n", nmax);
        for(j = 0; j < nmax; j++) {
            printf("%d ", nvmax);
        }
    }
    printf("\n");
    return 0;
}
