#include <stdio.h>

int bitcount(unsigned int n)
{
	int count = 0;
	while(n)
	{
		count += n & 0x1U;
		n >>= 1;
	}
	return count;
}

int main()
{
	unsigned int n;
	freopen("drakes.in",  "r", stdin);
	freopen("drakes.out", "w", stdout);
	scanf("%d", &n);
	printf("%d\n", bitcount(n));
	return 0;
}
