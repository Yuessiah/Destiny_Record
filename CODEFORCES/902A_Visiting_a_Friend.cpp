#include<cstdio>
#include<cstring>

const int maxn = 100 + 10;

int n, m, a[maxn], b[maxn];
bool vis[maxn][maxn];

bool solve(int p, int q, int t) {
	if(p <= m && m <= q) return true;

	for(int i = t; i < n; i++) if(!vis[a[i]][b[i]]) {
		vis[a[i]][b[i]] = true;
		if(p <= a[i] && a[i] <= q && q < b[i] && solve(a[i], b[i], i+1)) return true;
	}

	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);

	vis[a[0]][b[0]] = true;
	if(a[0] != 0) puts("NO");
	else puts(solve(a[0], b[0], 1)? "YES" : "NO");

	return 0;
}
