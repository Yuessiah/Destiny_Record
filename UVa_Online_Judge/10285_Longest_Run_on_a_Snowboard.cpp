#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int maxb = 1e2 + 10;

int R, C, B[maxb][maxb], dp[maxb][maxb];

int run(int r, int c) {
	if(dp[r][c]) return dp[r][c];

	int maxi = 1;
	for(int d = 0; d < 4; d++) {
		int rn = r + dy[d], cn = c + dx[d], tmp;
		if(rn >= 0 && rn < R && cn >= 0 && cn < C && B[rn][cn] < B[r][c]) tmp = 1 + run(rn, cn);
		maxi = max(maxi, tmp);
	}

	return dp[r][c] = maxi;
}

int main()
{
	int N;
	scanf("%d", &N);

	char name[100];
	while(N--) {
		memset(dp, 0, sizeof(dp));

		scanf("%s", name);
		scanf("%d%d", &R, &C);
		for(int r = 0; r < R; r++)
			for(int c = 0; c < C; c++) scanf("%d", &B[r][c]);

		int ans = 0;
		for(int r = 0; r < R; r++) for(int c = 0; c < C; c++) {
			int tmp = run(r, c);
			ans = max(ans, tmp);
		}
		printf("%s: %d\n", name, ans);
	}

	return 0;
}
