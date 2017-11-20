#include<bits/stdc++.h>
using namespace std;

const int INF = 0x7fffffff;
const int maxn = 2e3 + 10;

int n, a[maxn];

void solve()
{
	int cnt = 0;
	for(int i = 0; i < n; ++i) if(a[i] == 1) ++cnt;
	if(cnt > 0) { printf("%d\n", n - cnt); return; }

	int d = a[0];
	for(int i = 1; i < n; ++i) d = __gcd(d, a[i]);
	if(d > 1) { puts("-1"); return; }

	int ans = INF;
	for(int i = 0; i < n; ++i) {
		int d = a[i];
		for(int j = i; j < n; ++j) {
			d = __gcd(d, a[j]);
			if(d == 1) { ans = min(ans, j-i+n-1); break; }
		}
	}
	printf("%d\n", ans);
}

int main()
{
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

		solve();
	}

	return 0;
}
