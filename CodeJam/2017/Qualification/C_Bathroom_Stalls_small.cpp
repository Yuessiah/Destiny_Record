#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
using std::max;
const int maxn = 1000000;
const int INF = 0x7fffffff;

int n, k, p;

struct foo {
	int l, r, vis;
	int mini() { return min(l, r); }
	int maxi() { return max(l, r); }
}B[maxn];

int search()
{
	for(int i = 0; i < n; i++) { B[i].l = B[i].r = 0; }
	for(int i = 0; i < n; i++) if(!B[i].vis) {
		for(int j = i-1; j >= 0; j--) if(!B[j].vis) B[i].l++; else break;
		for(int j = i+1; j < n; j++) if(!B[j].vis) B[i].r++; else break;
	}

	int max_of_mini = 0, maxi = 0, maxi_p;
	for(int i = 0; i < n; i++) if(B[i].mini() > max_of_mini && !B[i].vis) max_of_mini = B[i].mini();
	for(int i = 0; i < n; i++) if(B[i].mini() == max_of_mini && B[i].maxi() > maxi && !B[i].vis) {
		maxi = B[i].maxi();
		maxi_p = i;
	}

	return maxi_p;
}

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		memset(B, 0, sizeof(B));

		scanf("%d%d", &n, &k);
		while(k--) B[p=search()].vis = 1;

		printf("Case #%d: %d %d\n", ++kase, B[p].maxi(), B[p].mini());
	}

	return 0;
}
