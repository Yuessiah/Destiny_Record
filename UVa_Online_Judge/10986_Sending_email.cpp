#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

const int maxn = 2e4 + 10;
const int INF = 0x3f3f3f3f;

struct node {
	int n, w;
	bool operator<(const node &lhs) const {
		return lhs.w < w;
	}
};

int n, m, S, T, d[maxn];
vector<node> E[maxn];
bool vis[maxn];

int main()
{
	int N, kase = 0;
	scanf("%d", &N);

	while(N--) {
		scanf("%d%d%d%d", &n, &m, &S, &T);

		for(int i = 0; i < n; i++) {
			E[i].clear();
			d[i] = INF;
			vis[i] = false;
		}

		int u, v, w;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			E[u].push_back((node){v, w});
			E[v].push_back((node){u, w});
		}

		priority_queue<node> Q;
		Q.push((node){S, d[S] = 0});

		while(!Q.empty()) {
			node now = Q.top(); Q.pop();

			for(auto nxt: E[now.n]) if(!vis[nxt.n]) {
				const int &update = d[now.n] + nxt.w;
				if(update < d[nxt.n]) {
					d[nxt.n] = update;
					Q.push((node){nxt.n, d[nxt.n]});
				}
			}

			vis[now.n] = true;
		}

		printf("Case #%d: ", ++kase);
		if(d[T] == INF) puts("unreachable");
		else printf("%d\n", d[T]);
	}

	return 0;
}
