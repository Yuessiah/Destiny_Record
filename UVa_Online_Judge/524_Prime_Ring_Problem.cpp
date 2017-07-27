#include<cstdio>
#include<cstring>
#include<cmath>
const int maxn = 15+16 + 10;

int A[maxn];
bool vis[maxn], isp[maxn];

bool is_prime(int n) {
	for(int i = 2; i <= (int)sqrt(n); i++) if(n%i == 0) return false;
	return true;
}

void dfs(int cur, int n) {
	if(cur == n && isp[A[cur-1]+A[0]]) {
		for(int i = 0; i < n; i++) printf("%d%c", A[i], (i==n-1)? '\n' : ' ');
	} else {
		for(int i = 1; i <= n; i++) if(!vis[i] && isp[A[cur-1]+i]) {
			A[cur] = i;
			vis[i] = true;
			dfs(cur+1, n);
			vis[i] = false;
		}
	}
}

int main()
{
	for(int i = 3; i <= maxn; i++) isp[i] = is_prime(i)? true : false;

	int n, kase=0;
	while(~scanf("%d", &n)) {
		memset(vis, 0, sizeof(vis));

		if(kase) putchar('\n');
		printf("Case %d:\n", ++kase);
		A[0] = 1; vis[1] = true; dfs(1, n);
	}

	return 0;
}
