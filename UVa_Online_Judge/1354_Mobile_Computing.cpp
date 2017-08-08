#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxs = 6;

struct len {
	double l, r;
	len(double l=0, double r=0): l(l), r(r){}
};

int s;
double ans, r, w[maxs], sum[1<<maxs];
bool vis[1<<maxs];
vector<len> libra[1<<maxs];

void dfs(int curr) { //current
	if(vis[curr]) return;
	else vis[curr] = true;

	if(__builtin_popcount(curr) == 1) { libra[curr].push_back(len(0, 0)); return; }

	for(int i = curr-1; i > 0; i--) {
		int left  = i & curr;
		int right = left ^ curr;
		dfs(left); dfs(right);

		double l_len = sum[right]/sum[curr];
		double r_len = sum[left] /sum[curr];

		for(int j = 0; j < libra[left].size(); j++)
			for(int k = 0; k < libra[right].size(); k++) {
				double total_l_len = min(libra[left][j].l - l_len, libra[right][k].l + r_len);
				double total_r_len = max(libra[left][j].r - l_len, libra[right][k].r + r_len);
				libra[curr].push_back(len(total_l_len, total_r_len));
			}
	}
}

void init() {
	ans = -1.0;
	memset(sum, 0, sizeof(sum));
	memset(vis, 0, sizeof(vis));
	vector<len> tmp[1<<maxs]; swap(tmp, libra);
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		init();

		scanf("%lf%d", &r, &s);
		for(int i = 0; i < s; i++) scanf("%lf", &w[i]);

		for(int i = 0; i < (1<<s); i++)
			for(int j = 0; j < s; j++) if(i & (1<<j)) sum[i] += w[j];

		int total = (1<<s)-1;
		dfs(total);
		for(int i = 0; i < libra[total].size(); i++) {
			double length = libra[total][i].r - libra[total][i].l;
			if(length > ans && length <= r) ans = length;
		}
		if(ans == -1.0) puts("-1");
		else printf("%.16lf\n", ans);
	}

	return 0;
}
