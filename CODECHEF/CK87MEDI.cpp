#include<cstdio>
#include<algorithm>
using std::sort;

const int maxn = 1e2 + 10;

int N, K, a[maxn];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i = 0; i < N; i++) scanf("%d", &a[i]);

		sort(a, a+N);
		int M = (N+K)>>1;
		printf("%d\n", a[M]);
	}

	return 0;
}
