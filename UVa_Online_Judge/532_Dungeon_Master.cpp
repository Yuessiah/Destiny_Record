#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;

const int size = 30 + 5;
const int dl[] = { 0, 0,  0, 0, -1, 1};
const int dr[] = {-1, 1,  0, 0,  0, 0};
const int dc[] = { 0, 0, -1, 1,  0, 0};

struct you {
	int l, r, c;
	you(int l=0, int r=0, int c=0): l(l), r(r), c(c){}
};

char maze[size][size][size];
int L, R, C, minute[size][size][size];
int sl, sr, sc;
bool vis[size][size][size];

int bfs() {
	queue<you> Q;
	vis[sl][sr][sc] = true;
	Q.push(you(sl, sr, sc));

	while(!Q.empty()) {
		you P = Q.front(); Q.pop();
		if(maze[P.l][P.r][P.c] == 'E') return minute[P.l][P.r][P.c];

		for(int d = 0; d < 6; d++) {
			int nl = P.l+dl[d], nr = P.r+dr[d], nc = P.c+dc[d];
			if(vis[nl][nr][nc] || nl >= L || nl < 0 || nr >= R || nr < 0 || nc >= C || nc < 0 || maze[nl][nr][nc] == '#') continue;
			vis[nl][nr][nc] = true;
			minute[nl][nr][nc] = minute[P.l][P.r][P.c] + 1;
			Q.push(you(nl, nr, nc));
		}
	}

	return -1;
}

int main()
{
	while(scanf("%d%d%d", &L, &R, &C) && (L || R || C)) {
		memset(vis, false, sizeof(vis));
		memset(minute, 0, sizeof(minute));

		for(int l = 0; l < L; l++)
			for(int r = 0; r < R; r++) {
				scanf(" %[^\n]%*c", maze[l][r]);
				for(int c = 0; c < C; c++)
					if(maze[l][r][c] == 'S') sl = l, sr = r, sc = c;
			}

		int ans = bfs();
		if(~ans) printf("Escaped in %d minute(s).\n", ans);
		else puts("Trapped!");
	}

	return 0;
}
