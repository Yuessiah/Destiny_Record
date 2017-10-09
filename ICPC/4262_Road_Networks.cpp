#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int maxn = 1e3 + 100;

int N, M, vis[maxn], cnt;
bool G[maxn][maxn];
stack<int> st;

void init() {
	cnt = 0;
	memset(G, 0, sizeof(G));
	memset(vis, 0, sizeof(vis));
}

void forward(int u) {
	vis[u] = 1;
	for(int v = 1; v <= N; v++) if(G[u][v] && !vis[v]) forward(v);
	st.push(u);
}

void backward(int u) {
	vis[u] = 1;
	for(int v = 1; v <= N; v++) if(G[v][u] && !vis[v]) backward(v);
}

void find_SCC() {
	for(int u = 1; u <= N; u++) if(!vis[u]) forward(u);
	memset(vis, 0, sizeof(vis));
	while(!st.empty()) {
		int the = st.top(); st.pop();
		if(vis[the]) continue;
		else {
			backward(the);
			cnt++;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		init();

		scanf("%d%d", &N, &M);
		for(int i = 0; i < M; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u][v] = 1;
		}
		scanf("%d", &M);

		find_SCC();
		printf("%d\n", cnt);
	}

	return 0;
}
