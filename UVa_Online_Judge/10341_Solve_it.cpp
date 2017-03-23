#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int p, q, r, s, t, u;
	while(~scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u)) {
		double x = 0.5, pre;
		int cnt = 100;
		do {
			pre = x;
			x = pre - (p*exp((-1)*pre) + q*sin(pre) + r*cos(pre) + s*tan(pre) + t*pow(pre, 2.0) + u)/((-1)*p*exp(-1*pre) + q*cos(pre) - r*sin(pre) + s*(1/pow(cos(pre), 2.0)) + 2*t*pre);
			if(!(cnt--)) { cnt = 0; break; }
		}while(fabs(pre - x) > 1e-8);

		if(cnt && ((x - 0.0) > -1e-8 && (x -1.0) < 1e-8)) printf("%.4f\n", fabs(x));
		else puts("No solution");
	}

	return 0;
}