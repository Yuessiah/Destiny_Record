#include<cstdio>
#include<cstring>
const int maxn = 4e4 + 10;

int n, p[maxn], dp[maxn];

int bs(int l, int r, int v) {
	while(l < r) {
		int m = l + ((r-l) >> 1);
		if(v <= dp[m]) r = m;
		else l = m + 1;
	}

	return l;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		memset(dp, 0, sizeof(dp));

		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &p[i]);

		int l = 0; //l := length
		dp[l++] = p[0];
		for(int i = 1; i < n; i++) {
			if(p[i] > dp[l-1]) dp[l++] = p[i];
			else {
				int vic = bs(0, l, p[i]);
				dp[vic] = p[i];
			}
		}

		printf("%d\n", l);
	}

	return 0;
}
