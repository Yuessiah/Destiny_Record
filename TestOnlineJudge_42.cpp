#include<cstdio>
const int maxn = 1000 + 10;

int h, w;
const int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
char map[maxn][maxn];

void dfs(int y, int x)
{
	for(int i = 0; i < 4; i++) {
		map[y][x] = '#';
		int n = dy[i], m = dx[i];
		if(y+n >= 0 && y+n < h && x+m >= 0 && x+m < w && map[y+n][x+m] == '.') dfs(y+n, x+m);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int cnt = 0;
		scanf("%d%d", &h, &w);
		for(int i = 0; i < h; i++) scanf("%s", map[i]);

		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(map[i][j] == '.') { ++cnt; dfs(i, j); }
		printf("%d\n", cnt);
	}
	return 0;
}
