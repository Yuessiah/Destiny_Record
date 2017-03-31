#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
const int maxm = 10200 + 10;

int dp[maxm];

int main()
{
	int budget, n;

	while(~scanf("%d%d", &budget, &n)) {
		memset(dp, 0, sizeof(dp));
		int refunded = (budget>1800)? budget+200 : budget;

		for(int i = 0; i < n; i++) {
			int price, value;
			scanf("%d%d", &price, &value);

			for(int j = refunded; j >= price; j--)
				if(dp[j-price] || j == price) dp[j] = max(dp[j], dp[j-price]+value);
		}

		int maximum = 0;
		for(int i = 1; i <= refunded; i++) {
			if(i > budget && i <= 2000) continue;
			maximum = max(maximum, dp[i]);
		}

		printf("%d\n", maximum);
	}

	return 0;
}
