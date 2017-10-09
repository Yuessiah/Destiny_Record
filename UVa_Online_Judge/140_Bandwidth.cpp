#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 8, INF = 0x7fffffff;

int series[maxn], ans[maxn], minbw, size;
bool vis[26], G[26][26];
char input[100];

int bandwidth(int a[maxn]) {
	int max = 0;
	for(int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++) {
			int v = series[j], u = series[i];
			if(G[u][v] && j-i > max) max = j-i;
		}

	return max;
}

void solve() {
	do {
		if(bandwidth(series) < minbw) {
			minbw = bandwidth(series);
			memcpy(ans, series, sizeof(series));
		}
	}while(next_permutation(series, series+size));
}

void init() {
	memset(G, 0, sizeof(G));
	memset(vis, 0, sizeof(vis));
	minbw = INF;
	size = 0;
}

int main()
{
	while(scanf("%s", input) && input[0] != '#') {
		init();

		bool gate = 1;
		int u, v;
		for(int i = 0; input[i] != 0; i++) {
			if(input[i] == ';') gate = 1;
			else if(input[i] == ':') gate = 0;
			else if(gate) u = input[i]-'A';
			else {
				v = input[i]-'A';
				G[u][v] = G[v][u] = 1;
				vis[u] = vis[v] = 1;
			}
		}

		for(int i = 0; i < 26; i++) if(vis[i]) series[size++] = i;

		solve();
		for(int i = 0; i < size; i++) printf("%c ", ans[i]+'A');
		printf("-> %d\n", minbw);
	}

	return 0;
}
