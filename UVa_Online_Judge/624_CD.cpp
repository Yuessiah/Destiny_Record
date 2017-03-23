#include<stdio.h>
#include<string.h>
const int maxn = 20 + 5;

int N, n, t[maxn], max;
bool ans[maxn], rec[maxn];

void solve(int d, int sum)
{
	if(d == n) {
		if(sum <= N && sum > max) {
			max = sum;
			memcpy(ans, rec, sizeof(rec));
		}
	} else {
		rec[d] = false;
		solve(d+1, sum);
		rec[d] = true;
		solve(d+1, sum+t[d]);
	}
}

int main()
{
	while(~scanf("%d", &N)) {
		max = 0;
		memset(rec, 0, sizeof(rec));

		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &t[i]);

		solve(0, 0);
		for(int i = 0; i < n; i++) if(ans[i]) printf("%d ", t[i]);
		printf("sum:%d\n", max);
	}

	return 0;
}
