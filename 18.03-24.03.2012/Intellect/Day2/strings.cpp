#include <string.h>
#include <limits.h>
#include <iostream>
#include <cstdio>

using namespace std;

char haystack[1000000],
     needle[1000000];
 
static int suffix_match(char *needle, size_t nlen, size_t offset, size_t suffixlen)
{
    if (offset > suffixlen)
        return needle[offset - suffixlen - 1] != needle[nlen - suffixlen - 1] &&
            memcmp(needle + nlen - suffixlen, needle + offset - suffixlen, suffixlen) == 0;
    else
        return memcmp(needle + nlen - offset, needle, offset) == 0;
}
 
static size_t max(size_t a, size_t b)
{
    return a > b ? a : b; 
}
 
char* memmem_boyermoore
    (char* haystack, size_t hlen,
     char* needle,   size_t nlen)
{
    size_t skip[nlen];
    size_t occ[UCHAR_MAX + 1];
 
    if(nlen > hlen || nlen <= 0 || !haystack || !needle) 
        return NULL;
 
    for(size_t a=0; a<UCHAR_MAX+1; ++a)
        occ[a] = -1;
 
    for(size_t a = 0; a < nlen - 1; ++a) 
        occ[needle[a]] = a;
 
    for(size_t a = 0; a < nlen; ++a)
    {
        size_t offs = nlen;
        while(offs && !suffix_match(needle, nlen, offs, a))
            --offs;
        skip[nlen - a - 1] = nlen - offs;
    }
 
    for(size_t hpos = 0; hpos <= hlen - nlen; )
    {
        size_t npos = nlen - 1;
        while(needle[npos] == haystack[npos + hpos])
        {
            if(npos == 0) 
                return haystack + hpos;
 
            --npos;
        }
        hpos += max(skip[npos], npos - occ[haystack[npos + hpos]]);
    }
    return NULL;
}

int main()
{
    long ans = 0, flag = 0, len, lh, ln;
    freopen("strings.in", "r", stdin);
    freopen("strings.out", "w", stdout);
    cin >> haystack >> needle;
    lh = strlen(haystack);
    ln = strlen(needle);
    while((ans = memmem_boyermoore(haystack+ans, lh-ans, needle, ln)-haystack-ans) >= 0)
    {
        if(lh-ans <= 0) break;
        flag = 1;
        printf("%ld ", ans+1);
        ans += ln;
    }
    if(!flag) printf("none\n");
    return 0;
}
