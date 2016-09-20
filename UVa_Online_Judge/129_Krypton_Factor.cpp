#include<stdio.h>
const int maxn = 80 + 9;

int n, L;
int cnt, a[maxn];

bool solve(int cur)
{
	if(cnt++ == n) {
		for(int i = 0; i < cur; i++) {
			if(i && i%64 == 0) putchar('\n');
			else if(i && i%4 == 0) putchar(' ');
			putchar('A'+a[i]);
		}
		printf("\n%d", cur);
		return 1;
	}

	for(int i = 0; i < L; i++) {
		int ok = 1;
		a[cur] = i;
		for(int j = 1; j*2 <= cur+1; j++) {
			int equal = 1;
			for(int k = 0; k < j; k++) {
				if(a[cur-k] != a[cur-k-j]) { equal = 0; break; }
			}
			if(equal) { ok = 0; break; }
		}
		if(ok && solve(cur+1)) return 1;
	}

	return 0;
}

int main()
{
	while(~scanf("%d%d", &n, &L) && (n || L)) {
		cnt = 0;
		solve(0);
		putchar('\n');
	}

	return 0;
}
