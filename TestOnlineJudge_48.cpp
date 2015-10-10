#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXL = 2000;

int bs(int l, int r, int* a, int x)
{
	int m;
	for(;;) {
		m = (l+r)>>1;
		if(a[m] == x) return m;
		if(a[m] > x) r = m-1; else l = m+1;
	}
}
void postorder(int n, int* pre, int* in)
{
	if(n == 0) return;
	int p = bs(0, n, in, pre[0]);
	postorder(p, pre+1, in);
	postorder(n-p-1, pre+p+1, in+p+1);
	printf("%d\n", pre[0]);
}

int main()
{
	int n = 0, pre[MAXL], in[MAXL];
	while(~scanf("%d", &pre[n])) { in[n] = pre[n]; n++; }
	std::sort(in, in+n); //inorder
	postorder(n, pre, in);
	return 0;
}
