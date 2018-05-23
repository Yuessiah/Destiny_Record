#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10, INF = 0x3f3f3f3f;

struct node {
	int n, w;
	bool operator<(const node &lhs) const {
		return w > lhs.w; // min heap
	}
};

int N, K, M;
bool vis[maxn];

int main()
{
	bool nl = false;
	while(~scanf("%d", &N)) {
		if(nl) putchar('\n'); else nl = true;

		vector<node> E[maxn];
		int sum = 0, u, v, w;

		for(int i = 0; i < N-1; i++) {
			scanf("%d%d%d", &u, &v, &w);
			sum += w;
		} printf("%d\n", sum);

		scanf("%d", &K);
		for(int i = 0; i < K; i++) {
			scanf("%d%d%d", &u, &v, &w);
			E[u].push_back((node){v, w});
			E[v].push_back((node){u, w});
		}

		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			scanf("%d%d%d", &u, &v, &w);
			E[u].push_back((node){v, w});
			E[v].push_back((node){u, w});
		}

		/* minimun spanning tree */

		memset(vis, false, sizeof(vis));
		sum = 0;
		priority_queue<node> Q;
		Q.push((node){1, 0}); // root

		while(!Q.empty()) {
			node u = Q.top(); Q.pop();

			if(!vis[u.n]) {
				sum += u.w;
				for(auto v: E[u.n]) if(!vis[v.n]) Q.push(v);
			}

			vis[u.n] = true;
		}

		printf("%d\n", sum);
	}

	return 0;
}
