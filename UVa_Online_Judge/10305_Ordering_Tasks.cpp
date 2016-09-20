#include<stdio.h>
#include<string.h>
const int maxn = 100;

int n, m;
bool E[maxn+9][maxn+9];
int c[maxn+9], t, topo[maxn+9];

bool dfs(int u)
{
	c[u] = -1;
	for(int v = 1; v <= n; v++) if(E[u][v]) {
		if(c[v] < 0) return false;
		if(!c[v]) if(!dfs(v)) return false;
	}

	c[u] = 1; topo[--t] = u;
	return true;
}

bool toposort()
{
	memset(c, 0, sizeof(c));
	t = n;
	for(int u = 1; u <= n; u++) if(!c[u] && !dfs(u)) return false;
	return true;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
		memset(E, 0, sizeof(E));
		int i, j;
		int cntdn = m;
		while(cntdn--) {
			scanf("%d%d", &i, &j);
			E[i][j] = 1;
		}

		if(toposort()) {
			for(int i = 0; i < n; i++) {
				printf("%d", topo[i]);
				if(i != n-1) putchar(' ');
			}
		} else printf("No");
		putchar('\n');
	}

	return 0;
}
