#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

const int maxn = 40 + 5;

int n, P[maxn][4], cap[4], dp[maxn][maxn][maxn][maxn];

int piles(set<int> basket) {
	if(basket.size() == 5) return 0;
	if(dp[cap[0]][cap[1]][cap[2]][cap[3]]) return dp[cap[0]][cap[1]][cap[2]][cap[3]];

	int maxi = 0;
	for(int i = 0; i < 4; i++) {
		if(cap[i] == n) continue;

		set<int> alt = basket;
		int pair = 0, top = P[cap[i]][i];
		if(alt.count(top)) { pair = 1; alt.erase(top); }
		else alt.insert(top);

		cap[i]++;
		int tmp = piles(alt) + pair;
		cap[i]--;

		maxi = max(maxi, tmp);
	}

	return dp[cap[0]][cap[1]][cap[2]][cap[3]] = maxi;
}

int main()
{
	while(scanf("%d", &n) && n) {
		memset(dp, 0, sizeof(dp));
		memset(cap, 0, sizeof(cap));

		for(int i = 0; i < n; i++)
			for(int j = 0; j < 4; j++) scanf("%d", &P[i][j]);

		printf("%d\n", piles(set<int>()));
	}

	return 0;
}
