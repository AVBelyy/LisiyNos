#include <stdio.h>
#include <math.h>

int check(long long x)
{
	double n = (x-1)*2;
	return (long long)(n) == (long long)(sqrt(n)) * (long long)(sqrt(n)+1);
}


int main()
{
	int i, n;
	long long index;
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d\n", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%lld\n", &index);
		printf("%d ", check(index));
	}
	printf("\n");
}
