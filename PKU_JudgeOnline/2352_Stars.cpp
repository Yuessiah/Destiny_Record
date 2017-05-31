#include<cstdio>
#include<cstring>
const int maxn = 15e3 + 10, maxx = 32e3 + 10;

int n, lvl[maxn], bit[maxx];

int lowbit(int x) { return x & -x; }

int sum(int x) {
	int s = 0;
	for(int i = x; i > 0; i-=lowbit(i)) s += bit[i];
	return s;
}

int main()
{
	while(~scanf("%d", &n)) {
		memset(lvl, 0, sizeof(lvl));
		memset(bit, 0, sizeof(bit));

		for(int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			x++;
			lvl[sum(x)]++;
			for(int j = x; j <= maxx; j+=lowbit(j)) bit[j]++;
		}

		for(int i = 0; i < n; i++) printf("%d\n", lvl[i]);
	}

	return 0;
}
