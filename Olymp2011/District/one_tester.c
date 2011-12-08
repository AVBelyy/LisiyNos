#include <stdio.h>

int main()
{
	int n, i = 0, cnt = 0;
	freopen("one.out",  "r", stdin);
	while(1)
	{
		scanf("%d", &n);
		if(feof(stdin)) break;
		i++;
		if(n == i) cnt++;
	}
	if(cnt == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
