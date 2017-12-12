#include<bits/stdc++.h>
using namespace std;

const int maxn = 22;

int n, route[maxn], cnt;
bool vis[maxn], G[maxn][maxn];
vector<int> R[maxn];

void dfs(int u, int d)
{
	if(u == n) {
		cnt++;
		for(int i = 0; i < d; i++) printf("%d%c", route[i], i<d-1? ' ' : '\n');
	} else for(int i = 0, l = R[u].size(); i < l; i++) {
		int v = R[u][i];

		if(!vis[v]) {
			vis[v] = true;
			route[d] = v;
			dfs(v, d+1);
			vis[v] = false;
		}
	}
}

bool isconnect()
{
	queue<int> Q;
	Q.push(1);

	bool ok = false;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		if(u == n) { ok = true; break; }

		for(int i = 0, l = R[u].size(); i < l; i++) {
			int v = R[u][i];
			if(vis[v]) continue;
			vis[v] = true;
			Q.push(v);
		}
	}

	memset(vis, false, sizeof(vis));

	return ok;
}

int main()
{
	int kase = 0;

	while(~scanf("%d", &n)) {
		cnt = 0;
		memset(G, false, sizeof(G));
		vector<int> tmp[maxn]; swap(tmp, R);

		int u, v;
		while(scanf("%d%d", &u, &v) && (u || v)) G[u][v] = G[v][u] = true;
		for(u = 1; u < maxn; u++)
			for(v = 1; v < maxn; v++) if(G[u][v]) R[u].push_back(v);

		printf("CASE %d:\n", ++kase);
		if(isconnect())  {
			vis[1] = true; route[0] = 1;
			dfs(1, 1);
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, n);
	}

	return 0;
}
