#include<cstdio>
#include<vector>
using std::vector;
vector<int> sum;

void dfs(int d, int parent, vector<vector<int> > &id)
{
	sum[d] = 1;
	for(int i = 0, len = id[d].size(); i < len; i++) {
		if(id[d][i] == parent) continue;
		dfs(id[d][i], d, id);
		sum[d] += sum[id[d][i]];
	}
}

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		vector<vector<int> > id(n);

		for(int i = 0; i < n-1; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			id[a].push_back(b); id[b].push_back(a);
		}

		sum.resize(n);
		dfs(0, 0, id);
		for(int i = 0; i < n; i++) printf("node %d: %d\n", i, sum[i]);
	}   
	return 0;
}
