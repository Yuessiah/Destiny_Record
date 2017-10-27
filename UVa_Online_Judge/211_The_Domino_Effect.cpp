#include<cstdio>
#include<cstring>

const int maxd = 28;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int R = 7, C = 8;

int cnt, maps[R][C], res[R][C], ans[100000][R][C], ans_n;

struct domino {
	int pip[2];
	bool vis;
} D[maxd+10];


void printResult(int arr[R][C]) {
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) printf("%4d", arr[r][c]);
		putchar('\n');
	} putchar('\n');
}

void dfs(int b) { //b := bone
	if(b > maxd) {
		for(int p = 0; p < ans_n; p++) if(!memcmp(ans[p], res, sizeof(res))) return;
		memcpy(ans[ans_n++], res, sizeof(res));

		printResult(res); cnt++;
	} else for(int r = 0; r < R; r++) for(int c = 0; c < C; c++) {
		if(!res[r][c] && maps[r][c] == D[b].pip[0] && !D[b].vis) {
			for(int d = 0; d < 4; d++) {
				int rn = r + dy[d], cn = c + dx[d];
				if(cn < 0 || cn >= C || rn < 0 || rn >= R) continue;

				if(!res[rn][cn] && maps[rn][cn] == D[b].pip[1]) {
					res[rn][cn] = res[r][c] = b; D[b].vis = true;
					dfs(b+1);
					res[rn][cn] = res[r][c] = 0; D[b].vis = false;
				}
			}
		}
	}
}

bool init() {
	cnt = ans_n = 0;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++) if(scanf("%d", &maps[i][j]) != 1) return false;
	return true;
}


int main()
{
	int bone = 1;
	for(int i = 0; i <= 6; i++) for(int j = i; j <= 6; j++) {
		D[bone].pip[0] = i;
		D[bone].pip[1] = j;
		bone++;
	}

	int kase = 0;
	while(init()) {
		if(kase) printf("\n\n\n");
		printf("Layout #%d:\n\n", ++kase);
		printResult(maps);
		printf("Maps resulting from layout #%d are:\n\n", kase);
		dfs(1);
		printf("There are %d solution(s) for layout #%d.\n", cnt, kase);
	}

	return 0;
}
