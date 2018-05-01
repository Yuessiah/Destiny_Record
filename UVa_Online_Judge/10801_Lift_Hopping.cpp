#include<cstdio>
#include<cstring>
#include<sstream>
#include<vector>
#include<queue>
#include<limits>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 6, maxf = 100;
const int INF = 0x3f3f3f3f;

struct node {
	int n, w;
	bool operator<(const node &lhs) const {
		return lhs.w < w;
	}
};

int n, k, T[maxn], F[maxf], d[maxf];
bool vis[maxf];

int main()
{
	while(~scanf("%d%d", &n, &k)) {
		vector<node> E[maxf];
		memset(vis, false, sizeof(vis));
		memset(d, 0x3f, sizeof(d)); //INF

		for(int i = 0; i < n; i++) scanf("%d", &T[i]);
		cin.ignore(numeric_limits<int>::max(), '\n'); //fuck getline.

		string line;
		for(int i = 0; i < n; i++) {
			getline(cin, line);
			stringstream ss(line);

			int f = 0;
			while(ss >> F[f++]); f--; //fuck again.
			for(int p = 0; p < f; p++) for(int q = p+1; q < f; q++) {
				int w = (F[q]-F[p])*T[i];
				E[F[p]].push_back((node){F[q], w});
				E[F[q]].push_back((node){F[p], w});
			}
		}

		priority_queue<node> Q;
		Q.push((node){0, d[0] = 0});
		while(!Q.empty()) {
			node now = Q.top(); Q.pop();
			vis[now.n] = true;

			for(auto nxt: E[now.n]) if(!vis[nxt.n]) {
				const int &update = d[now.n] + nxt.w + 60;
				if(update < d[nxt.n]) {
					d[nxt.n] = update;
					Q.push((node){nxt.n, update});
				}
			}
		}

		if(d[k] == INF) puts("IMPOSSIBLE");
		else printf(k? "%d\n" : "0\n", d[k]-60);
	}

	return 0;
}
