#include<cstdio>
#include<vector>
using std::vector;

void dfs(int x, const vector<vector<int> >& id, vector<int>& sum)
{
	if(sum[x]) return;
	sum[x] = 1;
	for(int i = 0, len = id[x].size(); i < len; i++) {
		dfs(id[x][i], id, sum);
		sum[x] += sum[id[x][i]];
	}
}

int main()
{
	int T, n, m;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		vector<vector<int> > id(n+1);
		while(m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			id[x].push_back(y);
		}

		vector<int> sum(n+1, 0);
		int q, x;
		scanf("%d", &q);
		while(q--) {
			scanf("%d", &x);
			dfs(x, id, sum);
			printf("%d\n", sum[x]);
		}
	}   
	return 0;
}
