#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

int n, lex[26], x;
string author[maxn];
bool G[26][26], vis[26], stat[26], ok;

bool dfs(int u) {
	stat[u] = true;

	for(int v = 0; v < 26; v++) if(G[u][v]) {
		if(stat[v]) return ok = false;

		if(!vis[v]) {
			vis[v] = true;
			if(!dfs(v)) return false;
			lex[x++] = v;
		}
	}

	stat[u] = false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//init
	ok = true, x = 0;
	memset(stat, false, sizeof(stat));
	memset(vis,  false, sizeof(vis));
	memset(G,    false, sizeof(G));

	cin >> n;
	for(int i = 0; i < n; i++) cin >> author[i];

	int k = 0;
	if(n >= 2) do {
		string &a = author[k];
		string &b = author[k+1];

		int i, al = a.size(), bl = b.size();
		for(i = 0; i < al && i < bl; i++) if(a[i] != b[i]) {
			int u = a[i]-'a', v = b[i]-'a';
			G[u][v] = true;
			break;
		}

		if(i == bl && al > bl) { ok = false; break; }
	} while(++k != n-1);

	for(int i = 25; i >= 0 && ok; i--) if(!vis[i]) {
		vis[i] = true;
		dfs(i);
		lex[x++] = i;
	}

	if(ok) for(int i = 25; i >= 0; i--) putchar(lex[i]+'a');
	else printf("Impossible");

	return 0;
}
