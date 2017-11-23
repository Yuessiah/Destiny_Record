#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned int n, b[32], p = 1;

	for(int i = 0; i <= 15; i++) {
		b[i] = p << i;
		p |= p << 1;
	}

	while(~scanf("%u", &n)) {
		for(int i = 15; i >= 0; i--) if(n % b[i] == 0) {
			printf("%u\n", b[i]);
			break;
		}
	}

	return 0;
}
