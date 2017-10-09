#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 100 + 10;

struct coordinate {
	double x, y;
}C[maxn];

struct edge {
	int a, b;
	double d;
	edge(int a=0, int b=0, double d=0): a(a), b(b), d(d){}
}E[maxn*maxn];

int group[maxn];

bool cmp(const edge& A, const edge& B) { return A.d < B.d; }

double dist(double x1, double y1, double x2, double y2) {
	double x = x1-x2;
	double y = y1-y2;
	return sqrt(x*x + y*y);
}

int find_set(int e) { return e == group[e]? e : find_set(group[e]); }

void union_set(int a, int b) { group[find_set(a)] = find_set(b); }

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		int n, k = 0;
		memset(C, 0, sizeof(C));
		memset(E, 0, sizeof(E));

		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			group[i] = i;

			scanf("%lf%lf", &C[i].x, &C[i].y);
			for(int j = 0; j < i; j++) E[k++] = edge(i, j, dist(C[i].x, C[i].y, C[j].x, C[j].y));
		}

		sort(E, E+k, cmp);
		double sum = 0.0;
		for(int i = 0; i < k; i++) if(find_set(E[i].a) != find_set(E[i].b)) {
			union_set(E[i].a, E[i].b);
			sum += E[i].d;
		}

		printf("%.2lf\n", sum);
		if(T) putchar('\n');
	}

	return 0;
}
