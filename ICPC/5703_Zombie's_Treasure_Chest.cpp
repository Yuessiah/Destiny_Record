#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	long long N, S1, V1, S2, V2;
	while(T--) {
		scanf("%lld%lld%lld%lld%lld", &N, &S1, &V1, &S2, &V2);

		long long big  = max(S1*V2, S2*V1),
				 used = N/(S1*S2),
				 sum = big * used,
				 left = N%(S1*S2);

		long long maxi = 0;
		if(S2 > S1) { swap(S1, S2); swap(V1, V2); }
		for(int i = 0; left >= S1*i; i++) {
			maxi = max(maxi, V1*i + ((left-S1*i)/S2)*V2);
		} sum += maxi;

		printf("Case #%d: %lld\n", ++kase, sum);
	}

	return 0;
}
