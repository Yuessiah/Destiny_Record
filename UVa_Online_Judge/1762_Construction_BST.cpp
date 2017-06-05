#include<cstdio>
#include<cmath>

int N, H;

void dfs(int l, int r, int dep) {
	if(dep == H || l > r) return;

	int right = (1 << H-dep-1) - 1, root;
	if(right > r-l) root = l; else root = r-right;

	printf(" %d", root);
	dfs(l, root-1, dep+1);
	dfs(root+1, r, dep+1);
}

int main()
{
	int kase = 0;

	while(scanf("%d%d", &N, &H) && (N || H)) {
		printf("Case %d:", ++kase);

		int total = (int)pow(2, H) - 1;
		if(N > total) printf(" Impossible.");
		else dfs(1, N, 0);
		putchar('\n');
	}

	return 0;
}
