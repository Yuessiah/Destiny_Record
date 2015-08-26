#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100000 + 9;

int n, m;
vector<pair<int, int> > G[maxn];
int d[maxn];
int vis[maxn], pre_color[maxn], min_color_of[maxn];

void init()
{
	for(int i = 0; i < maxn; i++) {
		G[i].clear();
		pre_color[i] = min_color_of[i] = INF;
	}
	memset(d, -1, sizeof(d));
	memset(vis, 0, sizeof(vis));
}

void bfs()
{
	queue<int> q;
	q.push(n);
	d[n] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0, len = G[u].size(); i < len; i++) {
			int v = G[u][i].first;
			if(d[v] == -1) { d[v] = d[u] + 1; q.push(v); }
		}
	}
}

void idealizing_output()
{
	queue<int> q;
	q.push(1);
	while(1) {
		int u = q.front(); q.pop();
		if(u == n) break;
		if(u != 1 && pre_color[u] != min_color_of[d[u]]) continue;

		for(int i = 0, len = G[u].size(); i < len; i++) {
			int v = G[u][i].first, c = G[u][i].second;
			if(d[v] == d[u] - 1) {
				if(!vis[v]) q.push(v), vis[v] = 1;
				pre_color[v] = min(pre_color[v], c);
				min_color_of[d[v]] = min(min_color_of[d[v]], c);
			}
		}
	}

	for(int i = d[1] - 1; i >= 0; i--) printf("%d%c", min_color_of[i], i == 0? '\n' : ' ');
}

int main()
{
	while(~scanf("%d%d", &n, &m)) {
		init();

		int u, v, c;
		int cntdn = m; while(cntdn--) {
			scanf("%d%d%d", &u, &v, &c);
			G[u].push_back(make_pair(v, c));
			G[v].push_back(make_pair(u, c));
		}

		bfs();
		printf("%d\n", d[1]);
		idealizing_output();
	}

	return 0;
}
