#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	int lim = b, cnt = 0;
	do {
		cnt++;

		a *= 10;
		int d = a/b;
		if(d == c) {
			printf("%d\n", cnt);
			break;
		}

		if(!(a%b) && c == 0) {
			printf("%d\n", cnt+1);
			break;
		}

		a = a%b;
	} while(--lim);

	if(!lim) puts("-1");

	return 0;
}
