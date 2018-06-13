#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int const maxn = 111, INF = 0x7fffffff;

int n, m, k, pre[2*maxn], flow[2*maxn], R[2*maxn][2*maxn];
bool vis[2*maxn];

int main()
{
	while(scanf("%d%d%d", &n, &m, &k) && n) {
		memset(R, 0, sizeof(R));
		int t = n+m+1;

		for(int i = 1; i <= n; i++) R[0][i] = 1;
		for(int i = 1; i <= m; i++) R[n+i][t] = 1;

		int x, y;
		for(int i = 0; i < k; i++) {
			scanf("%d%d%d", &x, &x, &y);
			if(x && y) R[x+1][n+y+1] = 1;
		}

		int max_flow = 0;
		while(1) {
			memset(vis, false, sizeof(vis));
			memset(flow, 0, sizeof(flow));
			queue<int> Q;
			Q.push(0); vis[0] = true; flow[0] = INF;

			while(!Q.empty()) {
				int u = Q.front(); Q.pop();

				for(int v = 0; v <= t; v++) if(R[u][v] && !vis[v]) {
					Q.push(v); vis[v] = true;
					flow[v] = min(flow[u], R[u][v]);
					pre[v] = u;
				}
			}
			if(flow[t] == 0) break;

			for(int v = t; v != 0; v = pre[v]) {
				int u = pre[v];
				R[u][v] -= flow[t];
				R[v][u] += flow[t];
			} max_flow += flow[t];
		}

		printf("%d\n", max_flow);
	}

	return 0;
}

