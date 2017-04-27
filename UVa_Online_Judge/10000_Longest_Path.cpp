#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
const int maxn = 100 + 10;

struct edge {
	int u, v;
	edge(int u=0, int v=0): u(u), v(v){}
}E[maxn*maxn];

int n, s, p, q, k, dist[maxn];

void tighten(int u, int v) {
	dist[v] = max(dist[v], dist[u] + 1);
}

int main()
{
	int kase = 0;
	while(scanf("%d", &n) && n) {
		k = 0;

		scanf("%d", &s);
		while(scanf("%d%d", &p, &q) && (p || q)) E[k++] = edge(p, q);

		//bellman
		memset(dist, -1, sizeof(dist));
		dist[s] = 0;
		for(int i = 1; i < n; i++)
			for(int j = 0; j < k; j++) {
				if(dist[E[j].u] == -1) continue;
				tighten(E[j].u, E[j].v);
			}

		//print answer
		int len = -1, end;
		for(int v = 1; v <= n; v++) if(len < dist[v]) {
			len = dist[v];
			end = v;
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++kase, s, len, end);
	}

	return 0;
}
