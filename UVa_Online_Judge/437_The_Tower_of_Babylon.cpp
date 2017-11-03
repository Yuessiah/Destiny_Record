#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;

const int maxn = 30 + 5;

struct block {
	int x, y, z;
}B[maxn*6];

int n, dp[maxn*6];

int base(int X, int Y, int idx) {
	if(dp[idx]) return dp[idx];

	int maxi = 0;
	for(int i = 0; i < n*6; i++) if(B[i].x < X && B[i].y < Y) {
		int tmp = base(B[i].x, B[i].y, i) + B[i].z;
		maxi = max(maxi, tmp);
	}

	return dp[idx] = maxi;
}

int main()
{
	int kase = 0;

	while(scanf("%d", &n) && n) {
		memset(dp, 0, sizeof(dp));

		int x, y, z;
		for(int i = 0; i < n*6; i+=6) {
			scanf("%d%d%d", &x, &y, &z);
			B[i+0].x = x; B[i+0].y = y; B[i+0].z = z;
			B[i+1].x = y; B[i+1].y = x; B[i+1].z = z;
			B[i+2].x = z; B[i+2].y = x; B[i+2].z = y;
			B[i+3].x = x; B[i+3].y = z; B[i+3].z = y;
			B[i+4].x = z; B[i+4].y = y; B[i+4].z = x;
			B[i+5].x = y; B[i+5].y = z; B[i+5].z = x;
		}

		int highest = 0;
		for(int i = 0; i < n*6; i++) {
			int tmp = base(B[i].x, B[i].y, i) + B[i].z;
			highest = max(highest, tmp);
		}

		printf("Case %d: maximum height = %d\n", ++kase, highest);
	}

	return 0;
}
