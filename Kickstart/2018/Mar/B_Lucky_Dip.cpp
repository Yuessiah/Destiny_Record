#include<cstdio>

const int maxn = 2e4 + 10;

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	int N, K;
	long long V[maxn], sum ;
	double E;

	while(T--) {
		sum = E = 0;

		scanf("%d%d", &N, &K);
		for(int i = 0; i < N; i++) {
			scanf("%lld", &V[i]);
			sum += V[i];
		} E = (double)sum / (double)N;

		while(K--) {
			double alt_E = 0;
			for(int i = 0; i < N; i++) alt_E += (V[i] >= E)? (double)V[i] : E;
			E = alt_E /= (double)N;
		}

		printf("Case #%d: %.6lf\n", ++kase, E);
	}

	return 0;
}
