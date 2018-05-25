#include<cstdio>
const int maxn = 51;

int n, a[maxn];

int main()
{
	while(~scanf("%d", &n)) {
		int pos, mini = 0x3f3f3f3f;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if(mini > a[i]) mini = a[pos = i];
		}

		int ans = 0;
		for(int i = pos+1; i < n-1; i++)
			ans += mini*a[i]*a[i+1];
		for(int i = pos-1; i >= 1; i--)
			ans += mini*a[i]*a[i-1];
		if(pos != 0 && pos != n-1) ans += a[0]*mini*a[n-1];

		printf("%d\n", ans);
	}

	return 0;
}
