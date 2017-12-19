#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;

vector<int> G[maxn];
int c[maxn], cnt;
bool vis[maxn];

void draw(int u, int p) {
	for(int i = 0, l = G[u].size(); i < l; i++) {
		int v = G[u][i];
		if(vis[v]) continue;
		//printf("(%d, %d) %d\n", u, v, c[u]);
		vis[v] = true;
		if(c[v] != p) cnt++;
		draw(v, c[v]);
	}
}

int main()
{
	memset(vis, 0, sizeof(vis));

	int n;
	scanf("%d", &n);

	int v;
	for(int i = 2; i <= n; i++) {
		scanf("%d", &v);
		G[i].push_back(v);
		G[v].push_back(i);
	}

	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);

	vis[1] = cnt = 1;
	draw(1, c[1]);
	printf("%d\n", cnt);

	return 0;
}
