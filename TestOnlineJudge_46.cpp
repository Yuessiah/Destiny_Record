#include<cstdio>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
const char colors[] = {'W', 'R', 'B', 'P', 'Y', 'O', 'G', 'D'};

int n;

struct drop {
	int c, x, y;
	drop(int c, int x, int y):c(c), x(x), y(y){}
};

int color(char c) { for(int i = 1; i <= 7; i++) if(c == colors[i]) return i; }
int merge(int a, int b) { return a | b; }
int bfs(int c, queue<drop>& q, vector<vector<int> >& map)
{
	if(c == 7) return n*n;
	int max = -1, chk = 0, t = 1, cnt = 0, ok = 0, bla = 3;

	while(!q.empty()) {
		drop dr = q.front(); q.pop();
		if(bla > 0 && dr.c == c) { cnt++; bla = 0; }
		else bla--;
		if(dr.c != chk) { t--; chk = dr.c; }
		if(t == 0) { if(max < cnt) max = cnt; t = 3; }

		for(int i = -1; i <= 1; i++)
			for(int j = -1; j <= 1; j++) {
				int dx = dr.x + i, dy = dr.y + j;
				if(dx >= 0 && dx < n && dy >= 0 && dy < n && (map[dy][dx] & dr.c) != dr.c && map[dy][dx] != 7) {
					if(map[dy][dx] == c) ok = 1;
					int m  = merge(map[dy][dx], dr.c); map[dy][dx] = m;
					if(ok && m != c) { cnt--; ok = 0; }
					if(!ok && m == c) cnt++;
					q.push(drop(dr.c, dx, dy));
				}
			}
	}
	return max;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		vector<vector<int> > map(n);
		for(int i = 0; i < n; i++) map[i].resize(n);
		int x, y, t = 3;
		char c[2];
		queue<drop> q;
		while(t--) {
			scanf("%s%d%d", c, &x, &y);
			map[y][x] = color(c[0]);
			q.push(drop(color(c[0]), x, y));
		}
		scanf("%s", c);
		printf("%d\n", bfs(color(c[0]), q, map));
	}
	return 0;
}
