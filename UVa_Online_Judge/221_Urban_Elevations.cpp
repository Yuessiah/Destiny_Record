#include<cstdio>
#include<algorithm>
const int maxn = 101 + 9;
using namespace std;

struct building {
	int id;
	double x, y, w, d, h;
	bool operator<(const building& p) const {
		return x < p.x || (x == p.x && y <= p.y);
	}
} b[maxn];
int N;
double x[maxn*2];

bool cover(int i, int mx) {
	return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible(int i, int mx)
{
	if(!cover(i, mx)) return false;
	for(int k = 0; k < N; k++) {
		if(cover(k, mx) && b[k].y < b[i].y && b[k].h >= b[i].h) return false;
	}
	return true;
}

int main()
{
	int kase = 0;
	while(scanf("%d", &N) && N) {
		for(int i = 0; i < N; i++) {
			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
			x[i*2] = b[i].x; x[i*2+1] = b[i].x + b[i].w;
			b[i].id = i+1;
		}

		sort(b, b+N);
		sort(x, x+N*2);
		int M = unique(x, x+N*2) - x;

		if(kase++) putchar('\n');
		printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase, b[0].id);
		for(int i = 1; i < N; i++) {
			bool vis = false;
			for(int j = 0; j < M; j++) {
				if(visible(i, (x[j]+x[j+1])/2)) { vis = true; break; }
			}
			if(vis) printf(" %d", b[i].id);
		}
		putchar('\n');
	}

	return 0;
}
