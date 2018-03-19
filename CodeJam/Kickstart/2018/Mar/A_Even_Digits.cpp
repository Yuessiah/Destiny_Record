#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T, kase = 0;
	scanf("%d\n", &T);

	while(T--) {
		long long sum = 0, U, D, n;
		bool start = false, nine = false;

		char in;
		while((in = getchar()) && in != '\n') {
			n = in - '0';
			if(start) {
				D *= 10;
				U *= 10;
				D += 8;
				if(nine) U += 8;
				sum *= 10;
				sum += n;
			} else if(n & 1) {
				start = true;
				if(n == 9) U = 8, nine = true;
				else U = n+1;
				D = n-1;
				sum = n;
			}
		}

		printf("Case #%d: ", ++kase);
		if(!start) puts("0");
		else printf("%lld\n", min(abs(sum - D), abs(sum - U)));
	}

	return 0;
}
