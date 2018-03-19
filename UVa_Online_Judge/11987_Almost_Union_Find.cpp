#include<cstdio>
#include<cstring>

const int maxn = 1e5 + 10;

int n, m, cmd, p, q;
int id[maxn], group[2*maxn], top_n[maxn], top_s[maxn];

int Find(int u) { return (group[u] == u)? u : group[u] = Find(group[u]); }

void Union(int u, int v) {
	int a = Find(id[u]), b = Find(id[v]);
	if(a == b) return;
	top_n[b] += top_n[a];
	top_s[b] += top_s[a];
	top_s[a] = top_n[a] = 0;
	group[a] = b;
}

void Move(int u, int v) {
	int a = Find(id[u]), b = Find(id[v]);
	if(a == b) return;
	top_n[b]++;
	top_n[a]--;
	top_s[b] += u;
	top_s[a] -= u;
	group[id[u] = ++n] = b;
	top_s[id[u]] = top_n[id[u]] = 0;
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) group[i] = id[i] = top_s[i] = i, top_n[i] = 1;

		while (m--) {
			scanf("%d", &cmd);
			switch (cmd) {
				case 1:
					scanf("%d%d", &p, &q);
					Union(p, q);
					break;
				case 2:
					scanf("%d%d", &p, &q);
					Move(p, q);
					break;
				case 3:
					scanf("%d", &p);
					int t = Find(id[p]);
					printf("%d %d\n", top_n[t], top_s[t]);
			}
		}
	}

	return 0;
}
