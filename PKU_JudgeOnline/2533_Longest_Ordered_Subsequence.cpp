#include<stdio.h>
const int maxn = 1000 + 10;

int n, a[maxn], lis[maxn];

int solve()
{
	int max = 0;
	for(int i = 0; i < n; i++) {
		lis[i] = 1;
		for(int j = 0; j < i; j++) {
			if(a[j] < a[i] && lis[j]+1 > lis[i]) lis[i] = lis[j]+1;
		}
		if(max < lis[i]) max = lis[i];
	}

	return max;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	printf("%d\n", solve());
}