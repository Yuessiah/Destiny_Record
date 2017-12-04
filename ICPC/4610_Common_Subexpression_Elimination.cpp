#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;

struct Node {
	string label;
	int ln, rn;
	bool operator < (const Node &b) const {
		if (label != b.label) return label < b.label;
		if (ln != b.ln) return ln < b.ln;
		return rn < b.rn;
	}
}N[maxn];

map<Node, int> M;
string E;
int nc, ec;
bool vis[maxn];

int parse() {
	int u = nc++;
	Node &P = N[u];
	N[u].ln = N[u].rn = -1;

	string label;
	while(isalpha(E[ec])) label.push_back(E[ec++]);
	P.label = label;

	if(E[ec] == '(') {
		ec++;
		P.ln = parse(); ec++;
		P.rn = parse(); ec++;
	}

	if(M.count(P)) { nc--; return M[P]; }
	return M[P] = u;
}

void printans(int u)
{
	Node &P = N[u];

	if(vis[u]) cout << u + 1;
	else {
		vis[u] = true;
		cout << P.label;
		if(P.ln != -1) {
			cout << '(';
			printans(P.ln);
			cout << ',';
			printans(P.rn);
			cout << ')';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c;
	cin >> c;

	while(c--) {
		//init
		nc = ec = 0;
		memset(vis, false, sizeof(vis));
		M.clear();

		cin >> E;
		printans(parse());
		cout << '\n';
	}

	return 0;
}
