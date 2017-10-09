#include<cstdio>
#include<cstring>
const int maxn = 2e6 + 100;

int n, a[maxn];

void mergesort(int l, int r) {
	if(r-l == 1) return;

	int m = l + (r-l)/2;
	mergesort(l, m);
	mergesort(m, r);

	int p = l, q = m, i = l, tmp[maxn];
	while(p != m || q != r) {
		if(p == m || (q != r && a[q] < a[p])) tmp[i++] = a[q++];
		else tmp[i++] = a[p++];
	}

	for(i = l; i < r; i++) a[i] = tmp[i];
}

int main()
{
	while(scanf("%d", &n) && n) {
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);

		mergesort(0, n);
		for(int i = 0; i < n; i++) printf("%d%c", a[i], (i==n-1)? '\n' : ' ');
	}

	return 0;
}
