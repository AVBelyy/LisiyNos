#include <stdio.h>
#include <string.h>

#define min(A, B)   (((A) < (B)) ? (A) : (B))

char S1[200001];
char S2[200001];

int main() {
    int n, i, j, cnt = 0;
    int l1 = 0, l2;
    freopen("typewriter.in", "r", stdin); 
    freopen("typewriter.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s", S2);
        l2 = strlen(S2); 
        // let us compute the number of keypresses for <CP>
        // for this, we need to compute the length of max common prefix
        // of S1 and S2
        int n = 0;
        for(j = 0; j < min(l1, l2); j++) {
            if(S1[j] == S2[j]) {
                n++;
            } else {
                break;
            }
        }
        cnt += min(1 + (l1-n) + (l2-n), l2) + 1;
        strncpy(S1, S2, l2);
        l1 = l2;
    }
    printf("%d\n", cnt-1);
    return 0;
}
