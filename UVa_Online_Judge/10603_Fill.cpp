#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 200 + 5;

int cap[3], x;
int vis[maxn][maxn], ans[maxn];

struct Node {
	int v[3], dist;
	Node(int a=0, int b=0, int c=0, int dist=0) {
		v[0] = a; v[1] = b; v[2] = c;
		this->dist = dist;
	}
	bool operator<(const Node& rhs) const {
		return dist > rhs.dist;
	}
};

void update_ans(const Node& u)
{
	for(int i = 0; i < 3; i++) {
		int d = u.v[i];
		if(ans[d] == -1 || ans[d] > u.dist) ans[d] = u.dist;
	}
}

void bfs()
{
	priority_queue<Node> q;
	Node start(0, 0, cap[2], 0);
	vis[0][0] = 1;
	q.push(start);

	while(!q.empty()) {
		Node u = q.top(); q.pop();
		update_ans(u);
		if(ans[x] >= 0) return;

		for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) if(i != j) {
			int amount = min(u.v[i], cap[j]-u.v[j]);
			Node v; memcpy(&v, &u, sizeof(u));
			v.v[i] -= amount;
			v.v[j] += amount;
			v.dist += amount;
			if(!vis[v.v[0]][v.v[1]]) {
				vis[v.v[0]][v.v[1]] = 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", cap, cap+1, cap+2, &x);
		memset(vis,  0, sizeof(vis));
		memset(ans, -1, sizeof(ans));

		bfs();
		do {
			if(ans[x] >= 0) {
				printf("%d %d\n", ans[x], x);
				break;
			}
		}while(x--);
	}

	return 0;
}
