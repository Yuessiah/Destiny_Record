#include<bits/stdc++.h>
using namespace std;

const int maxn = 360;

int main()
{
	int n, a[maxn];

	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);

		int mini = 360;
		for(int i = 0; i < n; i++) {
			int V = 0;
			for(int j = i; j < n; j++) {
				V += a[j];
				mini = min(mini, abs((360-V)-V));
			}
		}

		printf("%d\n", mini);
	}

	return 0;
}
