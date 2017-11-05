#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using std::min;
using std::max;

const int INF = 0x7fffffff;
const int maxn = 1e2 + 10;

int n;
double dp[maxn][maxn];

struct position {
	double x, y;
}p[maxn];

double dist(int a, int b) { return hypot(p[a].x-p[b].x, p[a].y-p[b].y); }

double tour(int a, int b) {
	if(dp[a][b]) return dp[a][b];
	if(a == n-2 || b == n-2) return dist(a, n-1) + dist(b, n-1);

	int nxt = max(a, b) + 1;
	return dp[a][b] = dp[b][a] = min(tour(a, nxt) + dist(b, nxt), tour(nxt, b) + dist(a, nxt));
}

int main()
{
	while(~scanf("%d", &n)) {
		memset(dp, 0, sizeof(dp));

		for(int i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
		printf("%.2lf\n", tour(0, 0));
	}

	return 0;
}
