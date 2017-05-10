#include<stdio.h>
int main()
{
	int a, b, c, d, e, f;
	while(scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) && a+b+c+d+e+f) {
		int res = c/4 + f + e + d; c %= 4;
		a -= 11*e; if(a < 0) a = 0;
		int x = b - 5*d;
		if(x < 0 && a > 0) a += 4*x;
		if(x < 0) x = 0;
		if(c > 0) {
			int z;
			if(x > 7-c*2) { z = 7-c*2; x -= z; } else { z = x; x = 0; }
			a -= 8-c + (7-c*2-z)*4; res++;
		} if(a < 0) a = 0;
		if(a+x > 0) res += (a+4*x-1)/36 + 1;
		printf("%d\n", res);
	}
	return 0;
}
