#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;

const int maxm = 3e4 + 100;

struct array {
	int val, ord;
}a[maxm];

int m, n;

bool cmp(const array& p, const array& q) { return p.val < q.val; }

int main()
{
	int K;
	scanf("%d", &K);

	while(K--) {
		scanf("%d%d", &m, &n);

		for(int i = 0; i < m; i++) {
			scanf("%d", &a[i].val);
			a[i].ord = i+1;
		}
		sort(a, a+m, cmp);

		for(int i = 0; i < n; i++) {
			int u, cnt = 0;
			scanf("%d", &u);
			for(int j = 0; j < m; j++) {
				if(a[j].ord <= u) cnt++;
				if(cnt == i+1) { printf("%d\n", a[j].val); break; }
			}
		}
		if(K) putchar('\n');
	}

	return 0;
}
