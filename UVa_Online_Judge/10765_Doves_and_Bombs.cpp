#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e4 + 100;

struct place {
	int s, p; //station, pigeon
	place(int s=0, int p=0): s(s), p(p){}
}P[maxn];

int n, m;
int G[maxn][maxn], top[maxn], lvl[maxn];

void init() {
	memset(lvl, 0, sizeof(lvl));
	memset(G, 0, sizeof(G));
	for(int i = 0; i < n; i++) P[i] = place(i, 1);
}

void dfs(int prev, int cur) {
	top[cur] = lvl[cur] = lvl[prev] + 1;
	int child = 0;

	for(int nxt = 0; nxt < n; nxt++) if(G[cur][nxt] && nxt != prev) {
		if(!lvl[nxt]) {
			child++;
			dfs(cur, nxt);
			top[cur] = min(top[cur], top[nxt]);
			if(lvl[cur] != 1 && top[nxt] >= lvl[cur]) P[cur].p++;
		} else top[cur] = min(top[cur], lvl[nxt]);
	}

	if(lvl[cur] == 1 && child > 1) P[cur].p = child;
}

bool cmp(const place& a, const place& b) {
	if(a.p == b.p) return a.s < b.s;
	return a.p > b.p;
}

void pigeon_count() {
	for(int u = 0; u < n; u++) if(!lvl[u]) dfs(u, u);
}

int main()
{
	while(~scanf("%d%d", &n, &m) && (n || m)) {
		init();

		int u, v;
		while(scanf("%d%d", &u, &v) && (~u || ~v)) G[u][v] = G[v][u] = 1;

		pigeon_count();
		sort(P, P+n, cmp);
		for(int i = 0; i < m; i++) printf("%d %d\n", P[i].s, P[i].p);
		putchar('\n');
	}

	return 0;
}
