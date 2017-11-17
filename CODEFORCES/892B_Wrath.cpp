#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 100;

int main()
{
	int n;
	long long L[maxn];

	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) scanf("%l64d", &L[i]);

		long long claw = L[n-1];
		int p = n;
		for(int i = n-2; i >= 0; i--) {
			if(claw > 0) p--;
			claw--;
			if(L[i] > claw) claw = L[i];
		}

		printf("%d\n", p);
	}

	return 0;
}
