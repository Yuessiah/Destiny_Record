#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;

const int maxs = 5e3 + 10;
const int INF = 0x3f3f3f3f;

char s1[maxs], s2[maxs];
int dp[maxs][maxs], l1, l2;
int fir1[26], fir2[26], las1[26], las2[26]; //the last/first position of character appearance.

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		//init
		memset(fir1, 0x3f, sizeof(fir1)); //INF
		memset(fir2, 0x3f, sizeof(fir2)); //INF
		memset(las1, -1,   sizeof(las1));
		memset(las2, -1,   sizeof(las2));

		scanf("%s%s", s1, s2);
		l1 = strlen(s1);
		l2 = strlen(s2);

		for(int i = 0; i < l1; i++) {
			int v = s1[i] - 'A';
			if(fir1[v] == INF) fir1[v] = i;
			las1[v] = i;
		}
		for(int i = 0; i < l2; i++) {
			int v = s2[i] - 'A';
			if(fir2[v] == INF) fir2[v] = i;
			las2[v] = i;
		}

		for(int a = l1; a >= 0; a--) for(int b = l2; b >= 0; b--) {
			int cnt = 0;
			for(int i = 0; i < 26; i++) {
				if((a > fir1[i] || b > fir2[i]) && (a <= las1[i] || b <= las2[i])) cnt++;
			}

			if(a == l1 && b == l2) { dp[a][b] = cnt; continue; }
			if(a == l1) { dp[a][b] = dp[a][b+1] + cnt; continue; }
			if(b == l2) { dp[a][b] = dp[a+1][b] + cnt; continue; }

			dp[a][b] = min(dp[a+1][b], dp[a][b+1]) + cnt;
		}

		printf("%d\n", dp[0][0]);
	}

	return 0;
}
