#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10, maxm = 2000 + 10;
const int INF = maxm*(1000+10);

int n, m, d[maxn], x[maxm], y[maxm], t[maxm];

void init()
{
	fill(d, d+n, INF);
	d[0] = 0;
}

void relax(int from, int to, int weight)
{
	d[to] = min(d[to], d[from] + weight);
}

bool bellman()
{
	init();

	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m; j++) relax(x[j], y[j], t[j]);

	for(int j = 0; j < m; j++) {
		int tmp = d[y[j]];
		relax(x[j], y[j], t[j]);
		if(d[y[j]] != tmp) return true;
	} return false;
}

int main()
{
	int c;
	scanf("%d", &c);

	while(c--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; i++) scanf("%d%d%d", &x[i], &y[i], &t[i]);

		if(bellman()) puts("possible");
		else puts("not possible");
	}

	return 0;
}
