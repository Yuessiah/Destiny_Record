#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 20 + 5;

struct pos {
	int r, c;
	pos(int r=0, int c=0): r(r), c(c){}
};

int n, m, k, dp[maxn][maxn][maxn][maxn];
bool che[maxn][maxn];


int check(int x1, int x2, int y1, int y2)
{
	int cnt = 0;
	for(int r = y1+1; r <= y2; r++)
		for(int c = x1+1; c <= x2; c++) if(che[r][c]) cnt++;

	if(cnt == 1) return 2;
	if(cnt <  1) return 1;
	return 0;
}

int cake(int x1, int x2, int y1, int y2)
{
	int &mini = dp[x1][x2][y1][y2];
	if(mini != -1) return mini;

	int status = check(x1, x2, y1, y2);
	if(status == 2) return mini = 0;
	if(status == 1) return mini = INF;

	mini = INF;
	for(int i = x1+1; i < x2; i++)
		mini = min(mini, cake(x1, i, y1, y2) + cake(i, x2, y1, y2) + (y2-y1));
	for(int i = y1+1; i < y2; i++)
		mini = min(mini, cake(x1, x2, y1, i) + cake(x1, x2, i, y2) + (x2-x1));
	return mini;
}

int main()
{
	int kase = 0;

	while(~scanf("%d%d%d", &n, &m, &k)) {
		//init
		memset(dp, -1, sizeof(dp));
		memset(che, false, sizeof(che));

		int r, c;
		for(int i = 0; i < k; i++) {
			scanf("%d%d", &r, &c);
			che[r][c] = true;
		}

		printf("Case %d: %d\n", ++kase, cake(0, m, 0, n));
	}

	return 0;
}
