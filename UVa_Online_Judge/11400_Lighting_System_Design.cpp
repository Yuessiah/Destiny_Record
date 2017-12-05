#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
const int INF = 0x7f7f7f7f;

struct lamp {
	int v, k, c, l;
}lam[maxn];

int n, dp[maxn], s[maxn];

bool cmp(const struct lamp& a, const struct lamp& b) { return a.v < b.v; }

int main()
{
	while(scanf("%d", &n) && n) {
		//init
		memset(lam, 0, sizeof(lam));
		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <= n; i++)
			scanf("%d%d%d%d", &lam[i].v, &lam[i].k, &lam[i].c, &lam[i].l);


		sort(lam+1, lam+n+1, cmp);
		s[0] = 0;
		for(int i = 1; i <= n; i++) s[i] = s[i-1] + lam[i].l;

		dp[0] = 0;
		for(int i = 1; i <= n; i++) {
			dp[i] = INF;
			for(int j = 0; j < i; j++) {
				dp[i] = min(dp[i], dp[j] + lam[i].c*(s[i]-s[j]) + lam[i].k);
			}
		}

		printf("%d\n", dp[n]);
	}

	return 0;
}
