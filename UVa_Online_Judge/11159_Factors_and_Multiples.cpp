#include<bits/stdc++.h>
using namespace std;

int const maxn = 111, INF = 0x7fffffff;

int n, m, a[maxn], b[maxn], R[2*maxn][2*maxn], flow[2*maxn], pre[2*maxn];
bool vis[2*maxn];

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		memset(R, 0, sizeof(R));

		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		scanf("%d", &m);
		for(int i = 1; i <= m; i++) scanf("%d", &b[i]);

		int t = n+m+1;
		for(int i = 1; i <= n; i++) {
			R[0][i] = 1;
			for(int j = 1; j <= m; j++) {
				R[i][n+j] = !b[j] || (a[i] && !(b[j]%a[i]));
				R[n+j][t] = 1;
			}
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

		printf("Case %d: %d\n", ++kase, max_flow);
	}

	return 0;
}
