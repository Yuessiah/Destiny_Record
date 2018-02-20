#include<cstdio>
#include<cmath>

int main()
{
	int T;
	scanf("%d", &T);

	long long Y;
	while(T--) {
		scanf("%lld", &Y);

		long long sum = 0;

		for(long long B = 1; B <= 700; B++) {
			long long cnt = sqrt(Y-B);
			if(cnt <= 0) break;
			sum += cnt;
		}
		printf("%lld\n", sum);
	}

	return 0;
}
