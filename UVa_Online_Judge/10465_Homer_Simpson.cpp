#include<bits/stdc++.h>
using namespace std;

const int maxt = 1e4 + 10;

int m[2], t; //m[0] := m, m[1] := n
int w[maxt], v[maxt], dp[maxt];

int main()
{
	while(~scanf("%d%d%d", &m[0], &m[1], &t)) {
		int K = 0, c = 2;
		while(c--) for(int i = 0; m[c]*pow(2, i) <= t; i++) {
			w[K] = m[c]*pow(2, i);
			v[K] = pow(2, i);
			K++;
		}

		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for(int i = 0; i < K; i++)
			for(int j = t; j >= w[i]; j--) {
				if(dp[j-w[i]] == -1) continue;
				dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
			}

		int burger, waste;
		for(int i = t; i >= 0; i--)
			if(dp[i] != -1) { burger = dp[i]; waste = t-i; break; }

		printf("%d", burger);
		if(waste) printf(" %d", waste);
		putchar('\n');
	}

	return 0;
}
