#include <stdio.h>

int l[3];

#define hyp l[0]
#define	a	l[1]
#define	b	l[2]

int compare(const void *x, const void *y)
{
	return (*(int*)y)-(*(int*)x);
}

int main()
{
	freopen("room.in",  "r", stdin);
	freopen("room.out", "w", stdout);
	scanf("%d%d%d", &l[0], &l[1], &l[2]);
	qsort(l, 3, sizeof(int), compare);
	if(hyp*hyp == a*a + b*b)
	{
		printf("YES\n1 1\n%d 1\n%d %d\n", 1+a, 1+a, 1+b);
	} else {
		printf("NO\n");
	}
	return 0;
}
