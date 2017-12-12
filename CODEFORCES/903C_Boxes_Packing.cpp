#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 10;

int main()
{
	int n, a[maxn], b[maxn], c[maxn];
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c)); // 0 := existed;

	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a+n);

	for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) {
		if(a[i] < a[j] && b[j] == 0) {
			c[i] = 1;
			b[j] = 1;
			break;
		}
	}

	int cnt = 0;
	for(int i = 0; i < n; i++) if(!c[i]) cnt++;
	printf("%d\n", cnt);

	return 0;
}
