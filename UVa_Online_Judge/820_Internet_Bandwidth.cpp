#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1e2 + 10;
const int INF = 0x7fffffff;

int n, s, t, c;
int R[maxn][maxn], pre[maxn], flow[maxn];
bool vis[maxn];

int ford_fulkerson() {
	int max_flow = 0;

	while(1) {
		memset(vis, false, sizeof(vis));
		memset(flow, 0, sizeof(flow));
		queue<int> Q;
		Q.push(s); vis[s] = true;
		flow[s] = INF;

		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int v = 1; v <= n; v++) if(R[u][v] && !vis[v]) {
				Q.push(v); vis[v] = true;
				flow[v] = min(flow[u], R[u][v]);
				pre[v] = u; //record path
			}
		}

		if(flow[t] == 0) break;
		for(int v = t; v != s; v = pre[v]) {
			int &u = pre[v];

			R[u][v] -= flow[t];
			R[v][u] += flow[t];
		} max_flow += flow[t];
	}

	return max_flow;
}

int main()
{
	int kase = 0;

	while(scanf("%d", &n) && n) {
		memset(R, 0, sizeof(R));

		scanf("%d%d%d", &s, &t, &c);
		for(int i = 0; i < c; i++) {
			int a, b, cap;
			scanf("%d%d%d", &a, &b, &cap);
			R[a][b] = R[b][a] += cap;
		}

		printf("Network %d\nThe bandwidth is %d.\n\n", ++kase, ford_fulkerson());
	}

	return 0;
}
