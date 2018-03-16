#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;

const int maxn = 1e3 + 10, INF = 0x7f7f7f7f;
const int dr[] = {0, 0, -1, 1}, dc[] = {-1, 1, 0, 0};

struct point { int r, c, t; };

int R, C, maze[maxn][maxn];
bool vis[maxn][maxn];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		memset(vis, false, sizeof(vis));

		queue<point> J, F;
		char input[maxn];

		scanf("%d%d", &R, &C);
		for(int r = 0; r < R; r++) {
			scanf("%s", input);
			for(int c = 0; c < C; c++) {
				if(input[c] == '#') maze[r][c] = 0;
				if(input[c] == '.') maze[r][c] = INF;
				if(input[c] == 'J') J.push((point){r, c, 0}), vis[r][c] = true;
				if(input[c] == 'F') F.push((point){r, c, 0});
			}
		}

		while(!F.empty()) {
			point f = F.front(); F.pop();

			for(int d = 0; d < 4; d++) {
				int nr = f.r+dr[d], nc = f.c+dc[d];
				if(nr == R || nc == C || nr < 0 || nc < 0 || maze[nr][nc] != INF) continue;
				maze[nr][nc] = f.t + 1;
				F.push((point){nr, nc, f.t+1});
			}
		}

		int escape = -1;
		while(!J.empty()) {
			point j = J.front(); J.pop();
			if(j.r == R-1 || j.c == C-1 || j.r == 0 || j.c == 0) { escape = j.t + 1; break; }

			for(int d = 0; d < 4; d++) {
				int nr = j.r+dr[d], nc = j.c+dc[d];
				if(vis[nr][nc] || j.t + 1 >= maze[nr][nc]) continue;
				vis[nr][nc] = true;
				J.push((point){nr, nc, j.t+1});
			}
		}

		if(~escape) printf("%d\n", escape);
		else puts("IMPOSSIBLE");
	}

	return 0;
}
