#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int maxp = 1e4/2 + 100;

struct coordinate {
	double x, y;
}C[maxp];

struct edge {
	int u, v;
	double d;
	edge(int u=0, int v=0, double d=0): u(u), v(v), d(d){}
}E[(1+maxp)*(maxp>>1)];

vector<double> D;
int S, P, k, group[maxp];

void init() {
	k = 0;
	D.clear();
}

bool cmp(const edge& A, const edge& B) { return A.d < B.d; }

double dist(double x1, double y1, double x2, double y2) {
	double x = x1 - x2, y = y1 - y2;
	return sqrt(x*x + y*y);
}

int find_set(int e) {
	if(group[e] == e) return e;
	return group[e] = find_set(group[e]);
}

void union_set(int a, int b) { group[find_set(a)] = find_set(b); }

int main()
{
	int N;
	scanf("%d", &N);

	while(N--) {
		init();

		scanf("%d%d", &S, &P);
		for(int i = 0; i < P; i++) {
			group[i] = i;

			scanf("%lf%lf", &C[i].x, &C[i].y);
			for(int j = 0; j < i; j++) {
				E[k++] = edge(i, j, dist(C[i].x, C[i].y, C[j].x, C[j].y));
				E[k++] = edge(j, i, dist(C[i].x, C[i].y, C[j].x, C[j].y));
			}
		}

		sort(E, E+k, cmp);
		for(int i = 0; i < k; i++) if(find_set(E[i].u) != find_set(E[i].v)) {
			union_set(E[i].u, E[i].v);
			D.push_back(E[i].d);
		}
		reverse(D.rbegin(), D.rend());
		//for(int i = 0; i < D.size(); i++) printf("%.2lf ", D[i]);
		printf("%.2lf\n", D[S-1]);
	}

	return 0;
}
