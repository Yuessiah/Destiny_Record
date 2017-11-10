#include<cstdio>
const int maxn = 1e4 + 10;

int n, a[maxn];

int main()
{
	while(~scanf("%d", &n)) {
		int cnt = 0;

		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 1; i < n-1; i++) {
			if(a[i] > a[i-1] && a[i] > a[i+1]) cnt++;
			if(a[i] < a[i-1] && a[i] < a[i+1]) cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}
