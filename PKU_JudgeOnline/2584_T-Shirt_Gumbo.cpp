#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define NUM(S, C) strchr(S, C)-S+X+1
using namespace std;

const char* SIZE = "SMLXT";
const int maxn = 30, INF = 0x7fffffff;

int X, S=0, T, R[maxn][maxn], pre[maxn];

void ford_fulkerson() {
	int max_flow = 0;
	while(1) {
		int flow[maxn] = {}, vis[maxn] = {};
		queue<int> Q;
		Q.push(S);
		flow[S] = INF;

		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int v = 1; v <= T; v++) if(R[u][v] && !vis[v]) {
				Q.push(v); vis[v] = 1;
				flow[v] = min(flow[u], R[u][v]);
				pre[v] = u;
			}
		}

		if(flow[T] == 0) break;
		for(int v = T, u = pre[T]; v != S; v=pre[v], u=pre[v]) {
			R[u][v] -= flow[T]; R[v][u] += flow[T];
		} max_flow += flow[T];
	}

	if(max_flow == X) puts("T-shirts rock!");
	else puts("I'd rather not wear a shirt anyway...");
}

void input() {
	scanf("%d", &X);
	T = X+strlen(SIZE)+1;
	for(int u = 1; u <= X; u++) {
		char A, B;
		scanf(" %c%c", &A, &B);
		for(int v = NUM(SIZE, A); v <= NUM(SIZE, B); v++) R[u][v] = 1;
		R[S][u] = 1;
	}
	for(int v = X+1; v <= X+strlen(SIZE); v++) scanf("%d", &R[v][T]);
}

int main()
{
	char s[30];
	while(scanf("%s", s) && strcmp(s, "ENDOFINPUT")) {
		memset(R, 0, sizeof(R));
		input();
		ford_fulkerson();

		scanf("%s", s);
	}

	return 0;
}
