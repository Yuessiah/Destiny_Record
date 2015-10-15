#include<stdio.h>
const int MAXN = 100000;

void swap(long long &a, long long &b) { long long t = a; a = b; b = t; }

int r;
long long q[MAXN+10];

void pq_push(long long x)
{
	q[++r] = x;
	int f = r/2, c = r;
	while(f != c) {
		if(q[c] < q[f]) swap(q[c], q[f]); else break;
		c = f; f /= 2;
	}
}

void pq_pop()
{
	int f = 1; q[1] = q[r--];
	while(f*2 <= r) {
		int c = f*2, c2 = f*2+1 <= r ? f*2+1 : c;
		if(q[c2] < q[c]) c = c2;
		if(q[c] < q[f]) swap(q[f], q[c]); else break;
		f = c;
	}
}

bool pq_empty() { return !r; }
long long pq_top() { return q[1]; }

int main()
{
	int n, x;
	while(scanf("%d", &n) && n) {
		r = 0;
		for(int i = 0; i < n; i++) { scanf("%d", &x); pq_push(x); }

		long long total = 0;
		for(;;) {
			long long a = pq_top(); pq_pop();
			long long b = pq_top(); pq_pop();
			total += a+b;
			if(!pq_empty()) pq_push(a+b); else break;
		}

		printf("%lld\n", total);
	}
	return 0;
}
