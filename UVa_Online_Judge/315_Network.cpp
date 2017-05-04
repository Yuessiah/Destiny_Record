#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int maxn = 100 + 10;

int n;
int lvl[maxn], top[maxn], G[maxn][maxn];
set<int> AP;

void init() {
	memset(lvl, 0, sizeof(lvl));
	memset(G, 0, sizeof(G));
	AP.clear();
}

void dfs(int prev, int cur, int dep) {
	lvl[cur] = top[cur] = dep;
	int child = 0;

	for(int nxt = 1; nxt <= n; nxt++) if(G[cur][nxt] && nxt != prev) {
		if(!lvl[nxt]) {
			child++;
			dfs(cur, nxt, dep+1);
			if(lvl[cur] != 1 && top[nxt] >= lvl[cur]) AP.insert(cur);
			else top[cur] = min(top[cur], top[nxt]);
		} else top[cur] = min(top[cur], lvl[nxt]);
	}

	if(lvl[cur] == 1 && child > 1) AP.insert(cur);
}

void find_AP() {
	for(int i = 1; i <= n; i++) if(!lvl[i]) dfs(i, i, 1);
}

int main()
{
	while(scanf("%d", &n) && n) {
		init();
		int u, v;
		char c;

		while(scanf("%d", &u) && u)
			while(scanf(" %d%c", &v, &c) && (G[u][v] = G[v][u] = 1) && c != '\n');

		find_AP();
		printf("%d\n", AP.size());
	}

	return 0;
}
