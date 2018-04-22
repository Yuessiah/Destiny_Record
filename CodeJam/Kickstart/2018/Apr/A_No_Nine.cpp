#include<cstdio>
#include<cstring>

const int maxs = 20;

long long F, L, b[maxs], dp[maxs][10];

long long dfs(int pos, bool top, int mod) {
	if(pos == -1) return mod != 0;
	if(!top && ~dp[pos][mod]) return dp[pos][mod];

	dp[pos][mod] = 0;
	for(int i = 0, e = top? b[pos] : 9; i <= e && i != 9; i++) {
		dp[pos][mod] += dfs(pos-1, top && (i == e), (mod * 10 + i) % 9);
	}

	return dp[pos][mod];
}

long long count(long long n) {
	int cnt = 0;
	memset(dp, -1, sizeof(dp));

	while(n) {
		b[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt-1, true, 0);
}

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		scanf("%lld%lld", &F, &L);
		printf("Case #%d: %lld\n", ++kase, count(L) - count(F-1));
	}

	return 0;
}
