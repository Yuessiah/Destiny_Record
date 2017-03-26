#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using std::min;

const double INF = 1e9;
const int maxk = 100 + 10;

double dp[maxk];

void solve()
{
	for(int i = 1; i <= maxk; i++)
		for(int j = 1; j < i; j++) dp[i] = min(dp[j]+dp[i-j], dp[i]);
}

int main()
{
	int kase = 0;

	while(~scanf("%lf", &dp[1])) {
		for(int i = 2; i <= maxk; i++) dp[i] = INF;

		int M;
		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			int n;
			double price;
			scanf("%d%lf", &n, &price);

			for(int j = n; j >= 1; j--) {
				if(dp[j] > price) dp[j] = price;
				else break;
			}
		}

		solve();

		printf("Case %d:\n", ++kase);
		while(1) {
			int k;
			char c;
			scanf("%d%c", &k, &c);
			printf("Buy %d for $%.2f\n", k, dp[k]);
			if(c == '\n') break;
		}
	}

	return 0;
}
