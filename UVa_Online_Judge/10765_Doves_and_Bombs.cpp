#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int maxn = 1e4 + 100;

int n, m, G[maxn][maxn], top[maxn], lvl[maxn];
map<int, int> AP;

void dfs(int prev, int cur) {
	top[cur] = lvl[cur] = lvl[prev] + 1;
	int child = 0;

	for(int nxt = 0; nxt < n; nxt++) if(G[cur][nxt] && nxt != prev) {
		if(!lvl[nxt]) {
			child++;
			dfs(cur, nxt);
			top[cur] = min(top[cur], top[nxt]);
			if(lvl[cur] != 1 && top[nxt] >= lvl[cur]) {
				if(AP.count(cur)) AP[cur]++;
				else AP[cur] = 1;
			}
		} else top[cur] = min(top[cur], lvl[nxt]);
	}

	if(lvl[cur] == 1 && child > 1) AP[cur] = 1;
}

void find_AP() {
	for(int u = 0; u < n; u++) if(!top[u]) dfs(u, u);
}

int main()
{
	while(~scanf("%d%d", &n, &m) && (n || m)) {
		int u, v;
		while(m-- && scanf("%d%d", &u, &v) && (G[u][v] = G[v][u] = 1));

		find_AP();
		for(auto it = AP.begin(); it != AP.end(); it++) printf("%d %d\n", (*it).first, (*it).second);
	}

	return 0;
}
