#include <stdio.h>

int main()
{
	int n, i;
	freopen("one.in",  "r", stdin);
	freopen("one.out", "w", stdout);
	scanf("%d", &n);
	switch(n)
	{
		case 2:
			printf("-1\n");
			break;
		default:
			if(n % 2 == 0)
			{
				for(i = 2; i < n; i++)
					printf("%d ", i);
				printf("%d %d\n", 1, n);
			} else {
				for(i = n; i > 0; i--)
					printf("%d ", i);
				printf("\n");
			}
	}
	return 0;
}
