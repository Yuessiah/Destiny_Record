#include<stdio.h>
#include<math.h>
#include<string.h>
const int maxn = 2000000;

int prime[maxn];

void create()
{
	for(int i = 2; i <= maxn; i++)
		for(int j = 2*i; j <= maxn; j+=i) {
			prime[j] = 0;
		}
}

int main()
{
	memset(prime, 1, sizeof(prime));
	create();

	long long int n;
	while(scanf("%lld", &n) && (n != -1)) {
		bool ok;
		do {
			ok = 0;

			int range  = (sqrt(n) < maxn)? sqrt(n) : maxn;
			for(long long int p = 2; p <= range; p++) if(prime[p] && !(n%p)) {
				ok = 1;
				printf("    %lld\n", p);
				n /= p;
				break;
			}
		}while(ok);
		if(n != 1) printf("    %lld\n", n);
		putchar('\n');
	}

	return 0;
}
