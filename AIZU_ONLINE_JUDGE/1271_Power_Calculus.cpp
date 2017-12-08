#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;

int n, maxd, p[maxn];

bool dfs(int d) {
	if(p[d] == n) return true;
	if(d == maxd) return false;

	int maxi = 0;
	for(int i = 0; i <= d; i++) maxi = max(maxi, p[i]);
	if(maxi*pow(2, maxd-d) < n) return false;

	for(int i = d; i >= 0; i--) {
		p[d+1] = p[d] + p[i];
		if(dfs(d+1)) return true;
		p[d+1] = p[d] - p[i];
		if(dfs(d+1)) return true;
	}

	return false;
}

int main()
{
	p[0] = 1;

	while(scanf("%d", &n) && n) {
		for(maxd = log2(n);; maxd++) if(dfs(0)) break;
		printf("%d\n", maxd);
	}

	return 0;
}
