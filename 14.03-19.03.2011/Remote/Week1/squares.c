#include <stdio.h>

#define max(x,y) (x) > (y) ? (x) : (y)

int main()
{
	long long i, a, b, c, k = 0, n = 0;
	freopen("squares.in", "r", stdin);
	freopen("squares.out", "w", stdout);
	/* fuckin' MinGW! */
	scanf("%I64d %I64d", &a, &b);
	do
	{
		if(a < b)
		{
			c = a;
			a = b;
			b = c;
		}
		k = a / b;
		for(i = 0; i < k; i++) printf("%I64d ", b);
		a %= b;
		n += k;
	} while(a);
	printf("\n");
	return 0;
}
