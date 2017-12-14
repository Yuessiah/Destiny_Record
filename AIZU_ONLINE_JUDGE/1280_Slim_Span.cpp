#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
const int INF = 0x3f3f3f3f;

struct edge { int a, b, w; };

int n, m, group[maxn];
vector<edge> G;

bool cmp(const edge& a, const edge& b) { return a.w < b.w; }

int Find(int v) { return (group[v] == v)? v : group[v] = Find(group[v]); }
void Union(int a, int b) { group[Find(a)] = Find(b); }


int main()
{
	while(scanf("%d%d", &n, &m) && n) {
		G.resize(m);
		for(int i = 0; i < m; i++) scanf("%d%d%d", &G[i].a, &G[i].b, &G[i].w);

		sort(G.begin(), G.end(), cmp);

		int mini = INF;
		for(int l = 0; l <= m-n+1; l++) {
			for(int i = 1; i <= n; i++) group[i] = i;

			int r, cnt = 0;
			for(r = l; r < m; r++) {
				int a = G[r].a, b = G[r].b;
				if(Find(a) != Find(b)) { Union(a, b); cnt++; }
				if(cnt == n-1) { mini = min(mini, G[r].w - G[l].w); break; }
			}
		}

		if(mini != INF) printf("%d\n", mini);
		else puts("-1");
	}

	return 0;
}
