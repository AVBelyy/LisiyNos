#include <math.h>
#include <stdio.h>

char oslinaya_mocha[] = ".000000";
char suda[sizeof(oslinaya_mocha)+12];

int main()
{
	double z, n, logn;
	double moosor; // DOUBLE MOOSOR!! HAHAHA! SUCK MY SWEATY BALLS!
	int ans = 1, govno;
	freopen("comb.in",  "r", stdin);
	freopen("comb.out", "w", stdout);
	scanf("%lf", &n);
	logn = log(n);
	for(z = 2; z < 31623; z++)
	{
		if(z == n) break;
		sprintf(suda, "%.6lf", modf(logn/log(z), &moosor));
		if(!strcmp(suda+1, oslinaya_mocha))
		{
			govno = moosor;
			govno += suda[0]-48;
			if(ans < govno) ans = govno;
		}
	}
	printf("%d\n", ans);
	return 0;
}
