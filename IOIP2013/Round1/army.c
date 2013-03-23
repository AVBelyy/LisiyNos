#include <stdio.h>
#include <stdint.h>

#define min(A, B)   (((A) < (B)) ? (A) : (B))
#define max(A, B)   (((A) > (B)) ? (A) : (B))

typedef struct {
    int flag;
    int min;
    int max;
} Node;

Node T[1<<16];

int process(int i, Node l, Node r) {
    T[i].min  = min(l.min, r.min);
    T[i].max  = max(l.max, r.max);
    T[i].flag = l.flag & r.flag;
    if(T[i].flag)
        if(l.max > r.min)
            T[i].flag = 0;
}

int build(int size) {
    int k, i;
    for(k = size; k > 0; k--) {
        for(i = (1<<(k-1))-1; i < (1<<k)-1; i++) {
            Node l = T[2*i+1], r = T[2*i+2]; 
            process(i, l, r);
        }
    }
}

// returns the least element in the segment [a; b]
int request(int v, int l, int r, int a, int b) {
    if(a == l && b == r)
        return T[v].min;
    if(a > b)
        return INT32_MAX;
    int m = (l+r)/2;
    return min(request(v*2+1, l, m, a, min(b, m)),
               request(v*2+2, m+1, r, max(a, m+1), b));
}

void update(int v, int val) {
    T[v].min = T[v].max = val;
    while(v > 0) {
        v = (v-1)/2;
        process(v, T[2*v+1], T[2*v+2]);
    }
}

int main() {
    int n, k, i, m;
    freopen("army.in", "r", stdin);
    freopen("army.out", "w", stdout);
    scanf("%d%d", &n, &m);
    // find the nearest k so as 2**k >= n
    for(i = 0; i <= 16; i++) {
        if(n <= 1<<i) {
            k = i;
            break;
        }
    }
    // required step for to search correctly
    for(i = (1<<k)+n-1; i < (1<<(k+1))-1; i++) {
        T[i].min = T[i].max = INT32_MAX;
        T[i].flag = 1;
    }
    // read the source
    for(i = 0; i < n; i++) {
        int buf, v = (1<<k)+i-1;
        scanf("%d", &buf);
        T[v].min = T[v].max = buf;
        T[v].flag = 1;
    }
    // build the tree
    build(k);
    // read them requests
    for(i = 0; i < m; i++) {
        char cmd;
        int v, val;
        scanf(" %c", &cmd);
        switch(cmd) {
            case '?':
                printf(T[0].flag ? "YES\n" : "NO\n");
                break;
            case '!':
                scanf("%d%d%", &v, &val);
                update((1<<k)+v-2, val);
                break;
        }
    }
    //printf("--> min(%d, %d) = %d\n", 1, 4, request(0, (1<<k)-1, (1<<(k+1))-2, (1<<k), (1<<k)+3));
}
