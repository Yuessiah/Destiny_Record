#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;

int N, vis[maxn];
vector<int> E[maxn];

int dfs(int p, int u, int d) {
	if(vis[u]) return vis[u]-1;
	vis[u] = d;

	for(auto v: E[u]) if(p^v) {
		int x = dfs(u, v, d+1);
		if(~x) return x;
	}

	return -1;
}

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) E[i].clear();

		int u, v;
		for(int i = 0; i < N; i++) {
			scanf("%d%d", &u, &v);
			E[u].push_back(v);
			E[v].push_back(u);
		}

		printf("Case #%d:", ++kase);
		for(int u = 1; u <= N; u++) {
			memset(vis, 0, sizeof(vis));
			printf(" %d", dfs(u, u, 1));
		} putchar('\n');
	}

	return 0;
}
