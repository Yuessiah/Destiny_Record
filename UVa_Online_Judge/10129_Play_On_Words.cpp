#include<stdio.h>
#include<string.h>
const int maxa = 26 + 9, maxl = 1000 + 9;

int N;
int E[maxa][maxa], I[maxa], O[maxa];
int vis[maxa];

void init()
{
	memset(E, 0, sizeof(E));
	memset(I, 0, sizeof(I));
	memset(O, 0, sizeof(O));
	memset(vis, 0, sizeof(vis));
}

void input()
{
	char s[maxl];
	scanf("%d", &N);
	while(N--) {
		scanf("%s", s);
		int p = s[0] - 'a';
		int q = s[strlen(s)-1] - 'a';
		E[p][q]++; E[q][p]++;
		O[p]++; I[q]++;
	}
}

void dfs(int u)
{
	vis[u] = 1;
	for(int v = 0; v < 26; v++) if(!vis[v] && E[u][v]) {
		dfs(v);
	}
}

bool is_connected()
{
	int cnt = 0;
	for(int u = 0; u < 26; u++) if(!vis[u] && O[u]) {
		dfs(u);
		cnt++;
	}

	if(cnt > 1) return false;
	return true;
}

bool is_eulerian()
{
	if(is_connected()) {
		int begin = 0, end = 0;
		for(int u = 0; u < 26; u++) if(O[u] != I[u]) {
			if(!begin && O[u] - I[u] == 1) begin++;
			else if(!end && I[u] - O[u] == 1) end++;
			else return false;
		}
		return true;
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		input();

		puts((is_eulerian()) ? "Ordering is possible." : "The door cannot be opened.");
	}

	return 0;
}
