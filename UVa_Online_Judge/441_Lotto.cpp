#include<stdio.h>
#include<string.h>
const int maxn = 13 + 5;

int n, a[maxn];
bool b[maxn];

void lotto(int step=0, int t=0)
{
	if(step == n) {
		if(t != 6) return;

		int sp = 6;
		for(int i = 0; i < n; i++) if(b[i]) {
			printf("%d", a[i]);
			if(--sp) putchar(' ');
		}
		putchar('\n');
	} else {
		b[step] = true;
		lotto(step+1, t+1);
		b[step] = false;
		lotto(step+1, t);
	}
}

int main()
{
	bool nl = false;
	while(scanf("%d", &n) && n) {
		memset(b, 0, sizeof(b));
		if(nl) putchar('\n');
		nl = true;

		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		lotto();
	}

	return 0;
}
