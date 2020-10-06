#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int maxn = 100 + 10;

int n, lvl[maxn], top[maxn], E[maxn][maxn];
set<int> AP;

void dfs(int u, int d) {
	lvl[u] = top[u] = d + 1;
	int c = 0;

	for(int v = 1; v <= n; v++) if(E[u][v]) {
		if(!lvl[v]) {
			c++, dfs(v, d+1);
			if(d && top[v] >= lvl[u]) AP.insert(u);
			else top[u] = min(top[u], top[v]);
		} else top[u] = min(top[u], lvl[v]);
	}

	if(!d && c > 1) AP.insert(u);
}

void init() {
	memset(lvl, 0, sizeof(lvl));
	memset(E, 0, sizeof(E));
	AP.clear();
}

int main()
{
	while(scanf("%d", &n) && n) {
		init();

		int u, v;
		char c;
		while(scanf("%d", &u) && u)
			while(scanf(" %d%c", &v, &c) && (E[u][v] = E[v][u] = 1) && c != '\n');

		for(int i = 1; i <= n; i++) if(!lvl[i]) dfs(i, 0);
		printf("%d\n", AP.size());
	}

	return 0;
}

