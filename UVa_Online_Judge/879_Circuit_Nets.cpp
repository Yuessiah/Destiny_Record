#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

const int maxn = 65535, maxs = 1e3;

int N, group[maxn];

int Find(int u) { return (u == group[u])? u : group[u] = Find(group[u]); }

int main()
{
	int T;
	scanf("%d", &T);
	getchar(); getchar();

	while(T--) {
		for(int i = 1; i <= maxn; i++) group[i] = i;
		scanf("%d", &N);
		getchar();

		int u, v;
		char input[maxs];
		while(fgets(input, maxs, stdin) != NULL) {
			if(input[0] == '\n') break;
			stringstream sin(input);
			while(sin >> u >> v) group[Find(u)] = Find(v);
		}


		int cnt = 0;
		for(int i = 1; i <= N; i++) if(Find(i) == i) cnt++;
		printf("%d\n", cnt);
		if(T) putchar('\n');
	}

	return 0;
}
