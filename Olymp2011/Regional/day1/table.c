#include <stdio.h>
#include <string.h>

#define SYM		'@'
#define P(x)	((x) < 0 ? s-1 : ((x) == s ? 0 : (x)))
#define S(x, y)	if(r[x] == SYM) r[x] = y;

char r[2001];

int main()
{
	memset(r, SYM, 2001);
	int s, m, i, n, t;
	freopen("table.in",  "r", stdin);
	freopen("table.out", "w", stdout);
	scanf("%d%d", &m, &n);
	s = m+n;
	r[s] = '\0';
	for(i = 0; i < s; i++)
	{
		// if we still have at least 1 boy...
		if(r[i] != 'G')
		{
			t = 0;
			if(r[P(i-1)] == SYM) t++;
			if(r[P(i+1)] == SYM) t++;
			if(n >= t)
			{
				if(r[i] != 'B' && m)
				{
					r[i] = 'B';
					m--;
				}
				n -= t;
				S(P(i-1), 'G');
				S(P(i+1), 'G');
			}
		}
		// and if we still have at least 1 girl...
		if(r[i] != 'B')
		{
			t = 0;
			if((t = r[P(i-1)]) != SYM)
			{
				if(t == 'B')
				{
					if(r[P(i+1)] != 'G' && n)
					{
						r[P(i+1)] = 'G';
						n--;
					}
					if(r[i] != 'G' && n)
					{
						r[i] = 'G';
						n--;
					}
				} else {
					if(r[P(i+1)] != 'B' && m)
					{
						r[P(i+1)] = 'B';
						m--;
					}
					if(r[i] != 'G' && n)
					{
						r[i] = 'G';
						n--;
					}
				}
			}
			if((t = r[P(i+1)]) != SYM)
			{
				if(t == 'B')
				{
					if(r[P(i-1)] != 'G' && n)
					{
						r[P(i-1)] = 'G';
						n--;
					}
					if(r[i] != 'G' && n)
					{
						r[i] = 'G';
						n--;
					}
				} else {
					if(r[P(i-1)] != 'B' && m)
					{
						r[P(i-1)] = 'B';
						m--;
					}
					if(r[i] != 'G' && n)
					{
						r[i] = 'G';
						n--;
					}
				}
			}
		}
	}
	// randomly set other boys & girls
	i = 0;
	while(n)
	{
		if(r[i] == SYM)
		{
			r[i] = 'G';
			n--;
		}
		i++;
	}
	i = 0;
	while(m)
	{
		if(r[i] == SYM)
		{
			r[i] = 'B';
			m--;
		}
		i++;
	}
	printf("%s\n", r);
	return 0;
}