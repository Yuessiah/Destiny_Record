#include<cstdio>
const int MAXN = 100000;
int T, n, m, word[MAXN];

bool copying(int x)
{
	int p = 0, l = 0;
	do {
		p++;
		int time = 0, i;
		for(i = l; time + word[i] <= x && i < n; i++) {
			time += word[i];
		} l = i;
	}while(p != m);

	return l == n;
}

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) scanf("%d", &word[i]);

		int r = 1, l, mid;
		while(!copying(r)) r = r<<1;
		l = r>>1;
		while(l != r) {
			mid = (l+r)>>1;
			if(copying(mid)) r = mid; else l = mid+1;
		}

		printf("%d\n", l);
	}
	return 0;
}
