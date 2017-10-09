#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 500 + 10, maxm = 2500 + 10, maxw = 200 + 10;
const int INF = 10000*(maxm+maxw);

int N, M, W;
int S[maxm+maxw], E[maxm+maxw], T[maxm], NT[maxw], dist[maxn];

void init()
{
	fill(dist, dist+N, INF);
	dist[N] = 0;
}

bool relax(int from, int to, int weight)
{
	int tmp = dist[to];
	dist[to] = min(dist[to], dist[from] + weight);
	return tmp != dist[to];
}

bool bellman()
{
	init();

	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < M; j++) {
			relax(S[j], E[j], T[j]);
			relax(E[j], S[j], T[j]);
		}
		for(int j = 0; j < W; j++) relax(S[M+j], E[M+j], (-1)*NT[j]);
	}

	for(int j = 0; j < M; j++) {
		if(relax(S[j], E[j], T[j])) return true;
		if(relax(E[j], S[j], T[j])) return true;
	}
	for(int j = 0; j < W; j++) if(relax(S[M+j], E[M+j], (-1)*NT[j])) return true;
	return false;
}

int main()
{
	int F;
	scanf("%d", &F);

	while(F--) {
		scanf("%d%d%d", &N, &M, &W);

		for(int i = 0; i < M; i++) scanf("%d%d%d", &S[i], &E[i], &T[i]);
		for(int j = 0; j < W; j++) scanf("%d%d%d", &S[M+j], &E[M+j], &NT[j]);

		if(bellman()) puts("YES");
		else puts("NO");
	}

	return 0;
}
