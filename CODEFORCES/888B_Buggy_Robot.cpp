#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	while(~scanf(" %d", &n)) {
		char c;
		int l, d, u, r;
		l = d = u = r = 0;

		for(int i = 0; i < n; i++) {
			scanf(" %c", &c);
			if(c == 'L') l++;
			if(c == 'D') d++;
			if(c == 'U') u++;
			if(c == 'R') r++;
		}

		printf("%d\n", (int)(max(l,r)-fabs(l-r) + max(u,d)-fabs(u-d))*2);
	}

	return 0;
}
