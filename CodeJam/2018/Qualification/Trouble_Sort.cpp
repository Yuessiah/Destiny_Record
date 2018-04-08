#include<cstdio>
#include<algorithm>
using std::sort;

const int maxn = 1e5 + 10, INF = 1e9 + 10;

int N, s1[maxn], s2[maxn];

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) {
			if(i&1) scanf("%d", &s2[i/2]);
			else scanf("%d", &s1[i/2]);
		}

		if(!(N&1)) s1[N/2] = INF; //dummy for loop invariant

		sort(s1, s1+N/2+1);
		sort(s2, s2+N/2);

		int ans = -1;
		for(int i = 0; i < N/2; i++) {
			if(s1[i+0] > s2[i]) { ans = 2*i+0; break; }
			if(s1[i+1] < s2[i]) { ans = 2*i+1; break; }
		}

		printf("Case #%d: ", ++kase);
		if(~ans) printf("%d\n", ans);
		else puts("OK");
	}

	return 0;
}
