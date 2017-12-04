#include<bits/stdc++.h>
using namespace std;

const int maxv = 1e3 + 10;

int V, E, T, degree[maxv], group[maxv], odd[maxv];
bool CC[maxv]; //connected components

int Find(int u) {
	if(group[u] == u) return u;
	return group[u] = Find(group[u]);
}

void Union(int u, int v) { group[Find(u)] = Find(v); }

int main()
{
	int kase = 0;

	while(~scanf("%d%d%d", &V, &E, &T) && (V || E || T)) {
		//init
		memset(degree, 0,     sizeof(degree));
		memset(odd,    0,     sizeof(odd));
		memset(CC,     false, sizeof(CC));
		for(int i = 1; i <= V; i++) group[i] = i;

		for(int i = 0, u, v; i < E; i++) {
			scanf("%d%d", &u, &v);
			degree[u]++; degree[v]++;
			Union(u, v);
		}

		for(int i = 1; i <= V; i++) if(degree[i]) {
			int g = Find(i);
			if(degree[i]%2) odd[g]++;
			CC[g] = true;
		}

		int way = -1;
		for(int i = 1; i <= V; i++) if(CC[i]) {
			way++;
			way += (odd[i] <= 1)? 0 : (odd[i]-1)/2;
		} way += E;

		printf("Case %d: %d\n", ++kase, E? way*T : 0);
	}

	return 0;
}
