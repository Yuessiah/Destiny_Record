#include<stdio.h>
#include<algorithm>
using std::sort;
const int maxr = 10 + 10, maxc = 100 + 10;
const int INF = 0x7fffffff;

int m, n, s[maxr][maxc], dp[maxr][maxc], next[maxr][maxc];

void solve()
{
	for(int c = n-1; c >= 0; c--) {
		for(int r = 0; r < m; r++) {
			if(c == n-1) dp[r][c] = s[r][c];
			else {
				int rows[] = {r-1, r, r+1};
				if(r == 0)   rows[0] = m-1;
				if(r == m-1) rows[2] = 0;
				sort(rows, rows+3);

				dp[r][c] = INF;
				for(int i = 0; i < 3; i++) {
					int v = dp[rows[i]][c+1] + s[r][c];
					if(v < dp[r][c]) { dp[r][c] = v; next[r][c] = rows[i]; }
				}
			}
		}
	}
}

int main()
{
	while(~scanf("%d%d", &m, &n)) {
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) scanf("%d", &s[i][j]);

		solve();

		int start, tmp = INF;
		for(int i = 0; i < m; i++) if(dp[i][0] < tmp) { tmp = dp[i][0]; start = i; }
		for(int i = start, j = 0; j < n; i = next[i][j], j++) { printf("%d", i+1); if(j < n-1) putchar(' '); }
		putchar('\n');
		printf("%d\n", dp[start][0]);
	}

	return 0;
}
