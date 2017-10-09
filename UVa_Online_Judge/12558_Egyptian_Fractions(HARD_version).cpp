#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;

const int maxn = 1e3, maxk = 5;

typedef long long int LL;

LL a, b, rstc[maxk], v[maxn], ans[maxn];
int k, maxd;

LL gcd(LL p, LL q) {
	return q? gcd(q, p%q) : p;
}

LL first(LL p, LL q) {
	return q/p + 1;
}

bool check(LL from) {
	for(int i = 0; i < k; i++)
		if(rstc[i] == from) return false;
	return true;
}

bool better() {
	for(int i = maxd; i >= 0; i--)
		if(ans[i] != v[i]) return (!ans[i] || v[i] < ans[i]);
	return false;
}

bool dfs(LL a1, LL b1, LL from, int d) {
	if(d == maxd) {
		v[d] = b1;
		if(a1 != 1 || !check(v[d])) return false;
		if(better()) memcpy(ans, v, sizeof(LL)*(maxd+1));
		return true;
	}

	bool ok = false;

	for(from = max(from, first(a1, b1));; from++) {
		/* (maxd-d+1)*(1/from) < a1/b1 */
		if((maxd-d+1)*b1 <= a1*from) break;
		if(!check(from)) continue;

		v[d] = from;
		/* a1/b1 - 1/from = a2/ b2 */
		LL a2 = a1*from - b1;
		LL b2 = b1*from;
		LL g = gcd(a2, b2);
		if(dfs(a2/g, b2/g, from+1, d+1)) ok = true;
	}

	return ok;
}

void solve() {
	for(maxd = 1;; maxd++) {
		memset(ans, 0, sizeof(ans));
		if(dfs(a, b, first(a, b), 0)) break;
	}
}


int main()
{
	int T, kase=0;
	scanf("%d", &T);

	while(T--) {
		scanf("%lld%lld%d", &a, &b, &k);
		for(int i = 0; i < k; i++) scanf("%lld", &rstc[i]);

		solve();
		printf("Case %d: %lld/%lld=", ++kase, a, b);
		for(int i = 0; i <= maxd; i++) printf("1/%lld%c", ans[i], (i==maxd)? '\n' : '+');
	}

	return 0;
}
