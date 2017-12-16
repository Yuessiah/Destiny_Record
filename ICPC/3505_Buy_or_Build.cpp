#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const int maxq = 9, maxn = 1e3 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct subnetwork {
	long long w;
	vector<int> V;
}sub[maxq];

struct edge {
	int u, v;
	long long w;
	edge(int u=0, int v=0, long long w=0): u(u), v(v), w(w){}
};

int n, q, m, x[maxn], y[maxn], group[maxn];
bool buy[maxq];
vector<edge> G, MST;

bool cmp(const edge& a, const edge& b) { return a.w < b.w; }
void disjoint_set_init() { for(int j = 1; j <= n; j++) group[j] = j; }
int Find(int v) { return (v == group[v])? v : group[v] = Find(group[v]); }


void buy_subnetwork(vector<edge> &B, const vector<int> &S) {
	for(int j = 0, l = S.size(); j < l; j++) for(int k = j+1; k < l; k++) {
		B.push_back(edge(S[j], S[k], 0));
	}
}

long long select_subnetworks(int enm) {
	if(enm == q) {
		vector<edge> SEL(MST);
		long long cost = 0;

		for(int i = 0; i < q; i++) if(buy[i]) {
			cost += sub[i].w;
			buy_subnetwork(SEL, sub[i].V);
		}

		disjoint_set_init();
		sort(SEL.begin(), SEL.end(), cmp);
		for(auto it: SEL) {
			int a = Find(it.u), b = Find(it.v);
			if(a != b) {
				group[a] = b; //union
				cost += it.w;
			}
		}

		return cost;
	} else {
		long long mini = INF;
		buy[enm] = true;
		mini = min(mini, select_subnetworks(enm+1));
		buy[enm] = false;
		mini = min(mini, select_subnetworks(enm+1));

		return mini;
	}
}


int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		G.clear();
		MST.clear();

		scanf("%d%d", &n, &q);
		for(int i = 0; i < q; i++) {
			scanf("%d%lld", &m, &sub[i].w);
			sub[i].V.resize(m);
			for(int j = 0; j < m; j++) scanf("%d", &sub[i].V[j]);
		}
		for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

		// build edge
		for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) {
			long long w = pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2);
			G.push_back(edge(i+1, j+1, w));
		}

		//construct MST
		disjoint_set_init();
		sort(G.begin(), G.end(), cmp);
		for(auto it: G) {
			int a = Find(it.u), b = Find(it.v);
			if(a != b) {
				group[a] = b;
				MST.push_back(edge(a, b, it.w));
			}
		}

		//print answer
		printf("%lld\n", select_subnetworks(0));
		if(T) putchar('\n');
	}

	return 0;
}
