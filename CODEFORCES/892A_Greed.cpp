#include<bits/stdc++.h>
using namespace std;

const long long maxn = 1e5 + 10;

int main()
{
	int n, a[maxn], b[maxn];

	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < n; i++) scanf("%d", &b[i]);

		sort(b, b+n);

		long long sum = 0;
		for(int i = 0; i < n; i++) sum += a[i];

		if(sum <= b[n-1] + b[n-2]) puts("YES");
		else puts("NO");
	}

	return 0;
}
