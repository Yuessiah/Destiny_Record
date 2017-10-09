#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
const int INF = maxn*10;

int n, R[maxn][maxn];

int main()
{
	while(scanf("%d", &n) && n) {
		for(int u = 1; u <= n; u++) fill(R[u]+1, R[u]+n+1, INF);

		for(int u = 1; u <= n; u++) {
			R[u][u] = 0;

			int m, v, t;
			scanf("%d", &m);
			while(m--) {
				scanf("%d%d", &v, &t);
				R[u][v] = t;
			}
		}

		//floyd
		for(int k = 1; k <= n; k++)
			for(int u = 1; u <= n; u++)
				for(int v = 1; v <= n; v++)
					R[u][v] = min(R[u][v], R[u][k] + R[k][v]);

		//find VIP
		int dur = INF, vip;
		for(int u = 1; u <= n; u++) {
			int maxi = 0;
			for(int v = 1; v <= n; v++) maxi = max(maxi, R[u][v]);
			if(dur > maxi) {
				vip = u;
				dur = maxi;
			}
		}

		if(dur == INF) puts("disjoint");
		else printf("%d %d\n", vip, dur);
	}

	return 0;
}
