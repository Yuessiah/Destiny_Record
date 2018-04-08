#include<cstdio>
#include<cstring>

const int maxp = 100;

int n, m, P[maxp+1];

int main()
{
	int T;
	scanf("%d", &T);

	for(int kase = 1; kase <= T; kase++) {
		memset(P, 0, sizeof(P));

		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &m);
			P[m]++;
		}

		printf("Case %d:\n", kase);
		bool first = true;
		for(int i = 0; i <= maxp; i++)
			while(P[i]) {
				if(!first) putchar(' '); else first = false;
				printf("%d", i);
				P[i]--;
			}
		putchar('\n');
	}

	return 0;
}
