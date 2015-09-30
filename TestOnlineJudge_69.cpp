#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 10000;
int T, n, k, c[MAXN], d=0;

struct horse {
	int a, b;
	int speed(int m=0) { return a+m*b; }
} h[MAXN];

int cmp(const void* _a, const void* _b)
{
	horse* a = (horse*)_a;
	horse* b = (horse*)_b;
	return a->speed(d) - b->speed(d);
}
bool win(int m)
{
	d = m;
	qsort(h, n, sizeof(horse), cmp);
	int kk = k;
	for(int i = 0, j = 0; i < n && kk; i++) {
		if(h[i].speed(m) > c[j]) { kk--; j++; }
	}
	if(kk == 0) return 1;
	return 0;
}

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; i++) scanf("%d%d", &h[i].a, &h[i].b);
		for(int i = 0; i < n; i++) scanf("%d", &c[i]);
		sort(c, c+n);
		qsort(h, n, sizeof(horse), cmp);

		vector<horse> t;
		for(int i = 0; i < n; i++) if(h[i].b == 0) t.push_back(h[i]);
		int zero = k - (n - t.size()), cc = 0;
		for(int i = 0, len = t.size(); i < len && zero > 0; i++) {
			if(t[i].a > c[cc]) { zero--; cc++; }
		} if(zero > 0) { printf("-1\n"); continue; }

		int l, r = 1, m;
		while(!win(r-1)) r = r<<1;
		l = r>>1;
		while(l != r) {
			m = (l+r)/2;
			if(win(m)) r = m; else l = m+1;
		}

		printf("%d\n", l);
	}
	return 0;
}
