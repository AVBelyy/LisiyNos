// TODO: lld -> I64d

#include <stdio.h>

int main()
{
	long long n, i, T, k;
	freopen("table.in",  "r", stdin);
	freopen("table.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	printf("%lld\n", (n-k)*(k-1)+1);
	return 0;
}
