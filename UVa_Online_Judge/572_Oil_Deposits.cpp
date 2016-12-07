#include<stdio.h>
#include<string.h>
const int maxn = 100 + 10;

int m, n;
int id_map[maxn][maxn];
char plot[maxn][maxn];

void dfs(int r, int c, int id)
{
	if(plot[r][c] != '@' || id_map[r][c] > 0) return;
	id_map[r][c] = id;

	for(int dr = -1; dr <= 1; dr++)
		for(int dc = -1; dc <= 1; dc++)
			if(r+dr >= 0 && r+dr < m && c+dc >= 0 && c+dc < n) dfs(r+dr, c+dc, id);
}

int main()
{
	while(scanf("%d%d", &m, &n) == 2 && m) {
		memset(id_map, 0, sizeof(id_map));
		for(int i = 0; i < m; i++) scanf("%s", plot[i]);

		int id = 0;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) if(plot[i][j] == '@' && id_map[i][j] == 0) dfs(i, j, ++id);

		printf("%d\n", id);
	}

	return 0;
}
