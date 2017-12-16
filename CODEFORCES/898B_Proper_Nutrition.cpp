#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);

	bool ok = false;

	for(long long i = 0; i <= n; i++) {
		if(i*a > n) break;
		if((n-i*a)%b == 0) {
			ok = true;
			printf("YES\n%lld %lld\n", i, (n-i*a)/b);
			break;
		}
	}

	if(!ok) puts("NO");

	return 0;
}
