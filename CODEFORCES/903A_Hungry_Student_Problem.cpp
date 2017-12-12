#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int main()
{
	bool dp[maxn];
	memset(dp, false, sizeof(dp));

	dp[3] = dp[7] = true;
	for(int i = 0; i < maxn; i++) {
		if(i >= 3 && (dp[i-3] || dp[i-7])) dp[i] = true;
	}

	int n, u;
	scanf("%d", &n);

	while(n--) {
		scanf("%d", &u);
		printf("%s\n", dp[u]? "YES" : "NO");
	}

	return 0;
}
