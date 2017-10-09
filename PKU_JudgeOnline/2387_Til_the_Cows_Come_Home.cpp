#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10, maxt = 2000 + 10;
const int INF = 100*maxt;

int T, N;
int U[maxt], V[maxt], d[maxn], w[maxt];

void init()
{
	fill(d, d+N, INF);
	d[N] = 0;
}

void relax(int u, int v, int i)
{
	d[v] = min(d[v], d[u] + w[i]);
}

void bellman()
{
	init();

	for(int i = 0; i < N-1; i++)
		for(int j = 0; j < T; j++) {
			relax(U[j], V[j], j);
			relax(V[j], U[j], j);
		}
}

int main()
{
	memset(w, 0, sizeof(w));

	while(~scanf("%d%d", &T, &N)) {
		for(int i = 0; i < T; i++) scanf("%d%d%d", &U[i], &V[i], &w[i]);

		bellman();
		printf("%d\n", d[1]);
	}

	return 0;
}
