#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 2*(1e2 + 10);
const int INF = 0x7fffffff;

int N, M, B, D, S=0, T;
int R[maxn][maxn], pre[maxn], flow[maxn];
bool vis[maxn];

int ford_fulkerson() {
	int max_flow = 0;
	while(1) {
		memset(vis, false, sizeof(vis));
		memset(flow, 0, sizeof(flow));
		queue<int> Q;
		Q.push(S);
		flow[S] = INF;

		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int v = 1; v <= T; v++) if(R[u][v] && !vis[v]) {
				Q.push(v); vis[v] = true;
				flow[v] = min(flow[u], R[u][v]);
				pre[v] = u;
			}
		}

		if(flow[T] == 0) break;
		for(int v = T; v != 0; v = pre[v]) {
			int& u = pre[v];
			R[u][v] -= flow[T];
			R[v][u] += flow[T];
		} max_flow += flow[T];
	}

	return max_flow;
}


void init() {
	memset(R, 0, sizeof(R));
	T = 2*N+1;
}

void input() {
		for(int i = 1; i <= N; i++) scanf("%d", &R[i][i+N]);
		scanf("%d", &M);
		int u, v, C;
		for(int i = 0; i < M; i++) { scanf("%d%d%d", &u, &v, &C); R[u+N][v] += C; }
		scanf("%d%d", &B, &D);
		for(int i = 0; i < B; i++) { scanf("%d", &v); R[S][v]   = INF; }
		for(int i = 0; i < D; i++) { scanf("%d", &u); R[u+N][T] = INF; }
}

int main()
{
	while(~scanf("%d", &N)) {
		init();
		input();
		printf("%d\n", ford_fulkerson());
	}

	return 0;
}
