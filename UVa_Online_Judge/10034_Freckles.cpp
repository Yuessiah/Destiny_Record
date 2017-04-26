#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 100 + 10;

struct coordinate {
	double x, y;
}C[maxn];

struct edge {
	int u, v;
	double d;
	edge(int u=0, int v=0, double d=0): u(u), v(v), d(d){}
}E[maxn*maxn*2];

int group[maxn];


bool cmp(const edge& A, const edge& B) { return A.d < B.d; }

double dist(double x1, double y1, double x2, double y2)
{
	double x = x1-x2;
	double y = y1-y2;
	return sqrt(x*x + y*y);
}

int find_set(int e) { return e == group[e]? e : find_set(group[e]); }

void union_set(int a, int b)
{
	int x = find_set(a), y = find_set(b);
	group[x] = y;
}


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
			for(int j = 0; j < i; j++) {
				E[k++] = edge(i, j, dist(C[i].x, C[i].y, C[j].x, C[j].y));
				E[k++] = edge(j, i, dist(C[i].x, C[i].y, C[j].x, C[j].y));
			}
		}

		sort(E, E+k, cmp);
		double sum = 0.0;
		for(int i = 0; i < k; i++) if(find_set(E[i].u) != find_set(E[i].v)) {
			union_set(E[i].u, E[i].v);
			sum += E[i].d;
		}

		printf("%.2lf\n", sum);
		if(T) putchar('\n');
	}

	return 0;
}
