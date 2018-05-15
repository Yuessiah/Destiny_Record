#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 2e3 + 10;

int N, M, top[maxn], dfn[maxn], n;
vector<int> E[maxn];

void dfs(int u) {
	dfn[u] = top[u] = n++;

	for(auto v: E[u]) {
		if(!top[v]) dfs(v);
		top[u] = min(top[u], top[v]); // the top value is a fake, but still useful
	}
}

int main()
{
	while(scanf("%d%d", &N, &M) && (N || M)) {
		memset(top, 0, sizeof(top));
		memset(dfn, 0, sizeof(dfn));
		vector<int> temp[maxn]; swap(E, temp);

		int V, W, P;
		for(int i = 0; i < M; i++) {
			scanf("%d%d%d", &V, &W, &P);
			E[V].push_back(W);
			if(P == 2) E[W].push_back(V);
		}

		dfs(n = 1); //calculate topper value

		int cnt = 0;
		for(int u = 1; u <= N; u++) if(dfn[u] == top[u]) cnt++;
		puts(cnt == 1? "1" : "0");
	}

	return 0;
}
