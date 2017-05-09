#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 750 + 10;

struct coordinate {
	int x, y;
}C[maxn];

struct edge {
	int a, b;
	double d;
	edge(int a=0, int b=0, double d=0): a(a), b(b), d(d){}
}E[maxn*maxn];

int N, M, group[maxn];

bool cmp(const edge& A, const edge& B) { return A.d < B.d; }

double dist(int x1, int y1, int x2, int y2) {
	double x = x1-x2, y = y1-y2;
	return sqrt(x*x + y*y);
}

int find_set(int e) {
	if(group[e] == e) return e;
	return group[e] = find_set(group[e]);
}

void union_set(int a, int b) { group[find_set(a)] = find_set(b); }

int main()
{
	int k = 0;

	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		group[i] = i;

		scanf("%d%d", &C[i].x, &C[i].y);
		for(int j = 1; j < i; j++) E[k++] = edge(i, j, dist(C[i].x, C[i].y, C[j].x, C[j].y));
	}

	scanf("%d", &M);
	for(int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		union_set(a, b);
	}

	bool ok = false;
	sort(E, E+k, cmp);
	for(int i = 0; i < k; i++) if(find_set(E[i].a) != find_set(E[i].b)) {
		ok = true;
		union_set(E[i].a, E[i].b);
		printf("%d %d\n", E[i].a, E[i].b);
	}
	if(!ok) puts("No new highways need");

	return 0;
}
