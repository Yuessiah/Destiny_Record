#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

long long n, x, k, a[maxn];

int main()
{
	scanf("%lld%lld%lld", &n, &x, &k);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

	long long cnt = 0;
	sort(a, a+n);
	for(int i = 0; i < n; i++) {
		long long b = (k-!(a[i]%x))*x + a[i];
		b -= b%x;
		cnt += lower_bound(a, a+n, b+x) - lower_bound(a, a+n, max(a[i], b));
	}

	printf("%lld\n", cnt);

	return 0;
}
