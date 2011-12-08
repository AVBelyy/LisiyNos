#include <math.h>
#include <stdio.h>

int main()
{
	int n, i, T, cnt = 0;
	freopen("nine.in",  "r", stdin);
	freopen("nine.out", "w", stdout);
	scanf("%d", &n);
	while(n)
	{
		for(i = 1; i < 31622; i++)
		{
			if(i*i > n) break;
			T = i;
		}
		n -= T*T;
		printf("%d ", T);
		cnt++;
	}
	for(i = 0; i < 9-cnt; i++) printf("0 ");
	printf("\n");
	return 0;
}
