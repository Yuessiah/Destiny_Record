#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stack>
using namespace std;

const int maxn = 26;

map<string, int> M;
stack<int> st;
vector<string> str;
int n, m;
bool vis[maxn], E[maxn][maxn], first;

void forward(int u) {
	vis[u] = true;
	for(int v = 0; v < maxn; v++)
		if(E[u][v] && !vis[v]) forward(v);
	st.push(u);
}

void backward(int u) {
	vis[u] = true;
	for(int v = 0; v < maxn; v++)
		if(E[v][u] && !vis[v]) backward(v);

	if(!first) cout << ", ";
	else first = false;
	cout << str[u];
}

void find_SCC() {
	for(int u = 0; u < n; u++) if(!vis[u]) forward(u);

	memset(vis, 0, sizeof(vis));
	while(!st.empty()) {
		int node = st.top(); st.pop();
		if(!vis[node]) {
			first = true;
			backward(node);
			putchar('\n');
		}
	}
}

void init() {
	map<string, int> temp; swap(M, temp);
	str.clear();
	memset(E, false, sizeof(E));
	memset(vis, false, sizeof(vis));
}

int main()
{
	int kase = 0;

	while(scanf("%d%d", &n, &m) && (n || m)) {
		init();
		int k = 0;

		string name1, name2;
		for(int i = 0; i < m; i++) {
			cin >> name1 >> name2;
			if(!M.count(name1)) M[name1] = k++, str.push_back(name1);
			if(!M.count(name2)) M[name2] = k++, str.push_back(name2);
			E[M[name1]][M[name2]] = true;
		}

		printf("Calling circles for data set %d:\n", ++kase);
		find_SCC();
	}

	return 0;
}
