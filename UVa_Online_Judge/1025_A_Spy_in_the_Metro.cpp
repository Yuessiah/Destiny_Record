#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 300, maxt = 300; //The range is not comformable in problem's constraints. fxxk!
const int INF = 0x7f7f7f7f;

int N, T, M1, M2;
int t[maxn], d[maxn], e[maxn], on_time[2][maxt][maxn], dp[maxt][maxn];

void init()
{
	memset(on_time, 0, sizeof(on_time));
}

void input()
{
	scanf("%d", &T);
	for(int i = 1; i <  N; i++) scanf("%d", &t[i]);
	scanf("%d", &M1);
	for(int i = 0; i < M1; i++) scanf("%d", &d[i]);
	scanf("%d", &M2);
	for(int i = 0; i < M2; i++) scanf("%d", &e[i]);
}

void station_schedule()
{
	for(int i = 0; i < M1; i++) {
		on_time[0][d[i]][1] = true;
		int dur = 0;
		for(int j = 1; j < N-1; j++){
			dur += t[j];
			on_time[0][d[i]+dur][j+1] = true;
		}
	}
	for(int i = 0; i < M2; i++) {
		on_time[1][e[i]][N] = true;
		int dur = 0;
		for(int j = N; j > 1+1; j--){
			dur += t[j-1];
			on_time[1][e[i]+dur][j-1] = true;
		}
	}
}

void solve()
{
	for(int i = 0; i <= T; i++) for(int j = 1; j < N; j++) dp[i][j] = INF;
	dp[T][N] = 0;

	for(int i = T-1; i >= 0; i--) for(int j = 1; j <= N; j++) {
		dp[i][j] = 1 + dp[i+1][j];
		if(on_time[0][i][j] && i+t[j  ] <= T) dp[i][j] = min(dp[i][j], dp[i+t[j  ]][j+1]);
		if(on_time[1][i][j] && i+t[j-1] <= T) dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
	}
}


int main()
{
	int kase = 0;

	while(scanf("%d", &N) && N) {
		init();
		input();

		station_schedule();
		solve();

		printf("Case Number %d: ", ++kase);
		if(dp[0][1] >= INF) puts("impossible");
		else printf("%d\n", dp[0][1]);
	}

	return 0;
}
