#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;

const int maxs = 1e3 + 10;

int len, dp[maxs];
bool pld[maxs][maxs];
char s[maxs];

void palindromes_check()
{
	for(int i = 0; i < len; i++) {
		int p = 2; //p := parity
		while(p--) for(int k = p; i+k < len && i-k+p >= 0; k++) {
			if(s[i+k] == s[i-k+p]) pld[i-k+p][i+k] = true;
			else break;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	while(n--) {
		memset(dp, 0, sizeof(dp));
		memset(pld, false, sizeof(pld));

		scanf("%s", s);
		len = strlen(s);

		palindromes_check();

		dp[0] = 1;
		for(int i = 1; i < len; i++) {
			dp[i] = (pld[0][i])? 1 : dp[i-1]+1;
			for(int j = 0; j < i; j++) {
				if(pld[j+1][i]) dp[i] = min(dp[i], dp[j]+1);
			}
		}
		printf("%d\n", dp[len-1]);
	}

	return 0;
}
