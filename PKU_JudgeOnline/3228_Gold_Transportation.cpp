#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 2e2 + 10;
const int INF = 1e6 + 10;

int N, M, u, v, d, g;
int gold[maxn], G[maxn][maxn];
bool vis[maxn];

bool can(int lim) {
	memset(vis, false, sizeof(vis));

	for(int S = 1; S <= N; S++) if(!vis[S]) {
		int storage = 0;
		queue<int> Q;
		Q.push(S); vis[S] = true;

		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			storage += gold[u];
			for(int v = 1; v <= N; v++) if(G[u][v] && G[u][v] <= lim && !vis[v]) {
				Q.push(v); vis[v] = true;
			}
		}

		if(storage > 0) return false;
	}

	return true;
}

void input() {
	for(int i = 1; i <= N; i++) { scanf("%d", &g); gold[i] += g; }
	for(int i = 1; i <= N; i++) { scanf("%d", &g); gold[i] -= g; }
	scanf("%d", &M);
	for(int i = 0; i < M; i++) {
		scanf("%d%d%d", &u, &v, &d);
		G[u][v] = G[v][u] += d;
	}
}

void init() {
	memset(gold, 0, sizeof(gold));
	memset(G, 0, sizeof(G));
}

int main()
{
	while(scanf("%d", &N) && N) {
		init();
		input();

		int lim = INF;
		//while(lim < INF) if(can(lim << 1)) break;

		int l = 0, r = lim;
		while(l < r) {
			int m = (l + r) >> 1;
			if(can(m)) r = m;
			else l = m + 1;
		}
		if(l == lim)  puts("No Solution");
		else printf("%d\n", l);
	}

	return 0;
}
