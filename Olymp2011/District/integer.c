#include <stdio.h>

int gcd(int a, int b)
{
	int c;
	while(a)
	{
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int main()
{
	int x1, y1, x2, y2;
	freopen("integer.in",  "r", stdin);
	freopen("integer.out", "w", stdout);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("%d\n", gcd(abs(x1-x2), abs(y1-y2))+1);
	return 0;
}
