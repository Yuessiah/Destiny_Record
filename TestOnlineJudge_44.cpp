#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;
const int max = 100;

int n;
const int y[] = {-1, 0, 1, 0}, x[] = {0, 1, 0, -1};
char map[max][max+1];
int vis[max][max];
struct nico {
	int f, s, cnt;
	nico():cnt(0){}
};

int bfs(int i, int j)
{
	queue<nico> q;
	nico p; p.f = i; p.s = j;
	q.push(p);
	while(!q.empty()) {
		p = q.front(); q.pop();
		int a = p.f, b = p.s;
		if(map[a][b] == '@') return p.cnt;
		p.cnt++;
		for(int d = 0; d < 4; d++) {
			if(!vis[a][b] && map[a+y[d]][b+x[d]] != '#') {
				p.f = a+y[d]; p.s = b+x[d];
				q.push(p);
			}
		}
		vis[a][b] = 1;
	}
	return 0;
}

int main()
{
	while(scanf("%d", &n) && n) {
		for(int i = 0; i < n; i++) scanf("%s", map[i]);
		memset(vis, 0, sizeof(vis));

		int ans;
		for(int i = 0; i < n; i++)
			for(int j = 0; map[i][j] != '\0'; j++) if(map[i][j] == 'K') ans = bfs(i, j);

		ans ? printf("%d", ans) : printf("= =\"");
		putchar('\n');
	}
	return 0;
}
