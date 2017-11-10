#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

char s[maxn];

int main()
{
	while(~scanf("%s", s)) {
		int len = strlen(s), ans = 0x7fffffff;

		for(int i = 0; i < 26; i++) {
			int k = 0, last = -1;
			for(int j = 0; j < len; j++) {
				if('a'+i == s[j]) {
					k = max(k, j-last);
					last = j;
				}
			}
			k = max(k, len-last);
			ans = min(ans, k);
		}

		printf("%d\n", ans);
	}

	return 0;
}
