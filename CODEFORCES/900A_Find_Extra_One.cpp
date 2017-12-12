#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int l = 0, r = 0, x, y;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		if(x < 0) l++;
		if(x > 0) r++;
	}

	if(l <= 1 || r <= 1) puts("Yes");
	else puts("No");

	return 0;
}
