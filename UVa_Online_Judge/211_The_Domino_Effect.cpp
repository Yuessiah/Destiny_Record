#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxd = 28 + 10;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

int cnt, bone, maps[7][8], res[7][8], ans[100000][7][8], ans_n;

struct domino {
	int pip[2];
	bool vis[2];
} D[maxd];

void dfs(int bone) {
	if(bone > 28) {
		for(int p = 0; p < ans_n; p++) if(!memcmp(ans[p], res, sizeof(res))) return;
		memcpy(ans[ans_n++], res, sizeof(res));

		for(int i = 0; i < 7; i++) {
			for(int j = 0; j < 8; j++) printf("%4d", res[i][j]);
			putchar('\n');
		} putchar('\n');
		cnt++;
	} else for(int i = 0; i < 7; i++) for(int j = 0; j < 8; j++) if(!res[i][j]) {
		if(maps[i][j] == D[bone].pip[0] && !D[bone].vis[0]) {
			D[bone].vis[0] = true;

			for(int d = 0; d < 4; d++) {
				int y_nxt = i + dy[d], x_nxt = j + dx[d];
				if(x_nxt < 0 || x_nxt >= 8 || y_nxt < 0 || y_nxt >= 7) continue;

				if(maps[y_nxt][x_nxt] == D[bone].pip[1] && !D[bone].vis[1] && !res[y_nxt][x_nxt]) {
					D[bone].vis[1] = true;
					res[y_nxt][x_nxt] = res[i][j] = bone;

					dfs(bone+1);

					D[bone].vis[1] = false;
					res[y_nxt][x_nxt] = res[i][j] = 0;
				}
			}

			D[bone].vis[0] = false;
		}
	}
}

void init() {
	cnt = ans_n = 0;
}

int main()
{
	int bone = 1;
	for(int i = 0; i <= 6; i++) {
		for(int j = i; j <= 6; j++) {
			D[bone].pip[0] = i;
			D[bone].pip[1] = j;
			bone++;
		}
	}

	int kase = 0;
	while(1) {
		init();

		for(int i = 0; i < 7; i++)
			for(int j = 0; j < 8; j++) if(scanf("%d", &maps[i][j]) != 1) return 0;

		if(kase) printf("\n\n\n");
		printf("Layout #%d:\n\n", ++kase);
		for(int i = 0; i < 7; i++) {
			for(int j = 0; j < 8; j++) printf("%4d", maps[i][j]);
			putchar('\n');
		} putchar('\n');

		printf("Maps resulting from layout #%d are:\n\n", kase);
		dfs(1);
		printf("There are %d solution(s) for layout #%d.\n", cnt, kase);
	}

	return 0;
}
