#include<stdio.h>
#include<stdlib.h>
const int MAXN = 10000;

struct people {
	int C, E;
}p[MAXN];

int cmp(const void *_a, const void *_b)
{
	people* a = (people*)_a;
	people* b = (people*)_b;
	return b->E - a->E;
}

int main()
{
	int N;
	while(scanf("%d", &N) && N) {
		for(int i = 0; i < N; i++) scanf("%d%d", &p[i].C, &p[i].E);

		qsort(p, N, sizeof(people), cmp);
		int t = 0, max = 0;
		for(int i = 0; i < N; i++) {
			t += p[i].C;
			if(max < t+p[i].E) max = t+p[i].E;
		}
		printf("%d\n", max);
	}
	return 0;
}
