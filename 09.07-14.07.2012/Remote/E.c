#include <stdio.h>
#include <string.h>

char s[256];

// Optimized EBNF from the Statement
char* anydigits(char* S) {
    if   (*S < '0'  ||  *S > '9') {
        return 0;
    }

    while('0' <= *S && *S <= '9') {
        S++;
    }

    return S;
}

char* exponent(char* S) {
    if(*S == 'e' || *S == 'E') {
        S++;

        if(*S != '+' && *S != '-') {
            return 0;
        }

        S++;

        if(*S < '1'  ||  *S > '9') {
            return 0;
        }
        return anydigits(S);
    } else {
        return S;
    }
}

char* fraction(char* S) {
    if(*S == '.') {
        S = anydigits(S + 1);
        return (S == 0) ? 0 : ((*(S - 1) == '0') ? 0 : S);
    } else {
        return S;
    }
}

char* mantissa(char* S) {
    if(*S < '1' || *S > '9') {
        return 0;
    }

    return fraction(S + 1);
}

char* real(char* S) {
    if(*S == '0') {
        return S + 1;
    } else {
        S = mantissa(S);
        return S ? exponent(S) : 0;
    }
}

int main() {
    int N, i;
    freopen("E.IN",  "r", stdin);
    freopen("E.OUT", "w", stdout);
    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        scanf("%s", s);
        printf(real(s) == s + strlen(s) ? "Yes\n" : "No\n");
    }

    return 0;
}
