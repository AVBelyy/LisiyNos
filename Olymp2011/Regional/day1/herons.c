#include <stdio.h>

int c[4];

int compare(const void *a, const void *b)
{
	return (*(int*)a) - (*(int*)b);
}

int main()
{
	int a, b;
	freopen("herons.in",  "r", stdin);
	freopen("herons.out", "w", stdout);
	scanf("%d%d", &a, &b);
	c[0] = a; c[1] = b;
	c[2] = c[0] / 2; if(c[2]*2 < c[0]) c[2]++;
	c[3] = c[1] / 2; if(c[3]*2 < c[1]) c[3]++;
	qsort(c, 4, sizeof(int), compare);
	// check for wrong uslovie
	if(c[1] > a) c[1] = a; if(c[1] > b) c[1] = b;
	if(c[2] > a) c[2] = a; if(c[2] > b) c[2] = b;
	printf("%d %d\n", c[1], c[2]);
	return 0;
}