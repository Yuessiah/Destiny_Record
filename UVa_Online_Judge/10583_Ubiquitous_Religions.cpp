#include<bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 100;

int n, m;
int group[maxn];
bool religion[maxn];

int find(int p)
{
	while(p != group[p]) p = group[p];
	return p;
}

int main()
{
	int kase = 0;

	while(~scanf("%d%d", &n, &m) && (n || m)) {
		for(int i = 1; i <= n; i++) group[i] = i;
		memset(religion, 0, sizeof(religion));

		int i, j;
		for(int l = 0; l < m; l++) {
			scanf("%d%d", &i, &j);
			int a = find(i), b = find(j);
			group[a] = b;
		}

		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(religion[find(i)] == false) cnt++;
			religion[find(i)] = true;
		}

		printf("Case %d: %d\n", ++kase, cnt);
	}

	return 0;
}
