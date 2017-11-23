#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;

int vis[maxn], c[maxn];
vector<int> G[maxn];

void dfs(int u, int &gold)
{
	for(int i = 0, l = G[u].size(); i < l; i++) {
		int v = G[u][i];
		if(vis[v]) continue;
		vis[v] = true;
		gold = min(gold, c[v]);
		dfs(v, gold);
	}
}

void init()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < maxn; i++) G[i].clear();
}

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		init();

		for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
		int u, v;
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		long long sum = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			int g = c[i];
			dfs(i, g);
			sum += g;
		}

		printf("%lld\n", sum);
	}

	return 0;
}
