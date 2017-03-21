#include<stdio.h>
#include<math.h>

double B, H;

double solve()
{
	double sum = 0.0;
	while(1) {
		double theta = atan2(H, B/2);
		double r = (B/2)*tan(theta/2);
		if(r < 0.000001) break;

		sum += 2*r*2*asin(1);
		double tmp = H - 2*r;
		B = tmp*(B/H);
		H = tmp;
	}

	return sum;
}

int main()
{
	int T;
	scanf("%d", &T);

	bool nl = false;
	while(T--) {
		if(nl) putchar('\n');
		nl = true;
		scanf("%lf%lf", &B, &H);
		printf("%13.6f\n", solve());
	}

	return 0;
}
