#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

const int maxn = 1e3 + 10;

int n, G[maxn][maxn], lvl[maxn], top[maxn];
vector<pair<int, int> > BG;

void init() {
	BG.clear();
	memset(lvl, 0, sizeof(lvl));
	memset(G, 0, sizeof(G));
}

void dfs(int prev, int cur) {
	lvl[cur] = top[cur] = lvl[prev] + 1;

	for(int nxt = 0; nxt < n; nxt++) if(G[cur][nxt] && nxt != prev) {
		if(!lvl[nxt]) {
			dfs(cur, nxt);
			if(top[nxt] > lvl[cur]) BG.push_back(make_pair(min(cur, nxt), max(cur, nxt)));
			else top[cur] = min(top[cur], top[nxt]);
		} else top[cur] = min(top[cur], lvl[nxt]);
	}
}

void find_BG() {
	for(int i = 0; i < n; i++) if(!lvl[i]) dfs(i, i);
}

int main()
{
	while(~scanf("%d", &n)) {
		init();

		for(int i = 0; i < n; i++) {
			int u, v, m;
			scanf("%d ", &u);
			getchar(); scanf("%d", &m); getchar();
			for(int j = 0; j < m; j++) {
				scanf("%d", &v);
				G[u][v] = G[v][u] = 1;
			}
		}

		find_BG();
		printf("%d critical links\n", BG.size());
		sort(BG.begin(), BG.end());
		int len = BG.size();
		for(int i = 0; i < len; i++) printf("%d - %d\n", BG[i].first, BG[i].second);
		putchar('\n');
	}

	return 0;
}
