#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 10, maxm = 15000 + 100;

struct edge {
	int a, b, d;
}E[maxm];

int N, M, group[maxn];
vector<edge> path;

bool cmp(const edge& A, const edge& B) { return A.d < B.d; }

int find_set(int e) {
	if(e == group[e]) return e;
	return group[e] = find_set(group[e]);
}

void union_set(int a, int b) { group[find_set(a)] = find_set(b); }

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) group[i] = i;

	for(int i = 0; i < M; i++) scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].d);

	sort(E, E+M, cmp);
	for(int i = 0; i < M; i++) if(find_set(E[i].a) != find_set(E[i].b)) {
		union_set(E[i].a, E[i].b);
		path.push_back(E[i]);
	}

	int len = path.size();
	printf("%d\n%d\n", path[len-1].d, len);
	for(int i = 0; i < len; i++) printf("%d %d\n", path[i].a, path[i].b);

	return 0;
}
