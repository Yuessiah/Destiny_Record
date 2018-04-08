#include<cstdio>
#include<cstring>

const int maxl = 30 + 5;

long long D, L[maxl];
char P[maxl];

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		scanf("%lld%s", &D, P);

		int p_l = strlen(P), total = 0, strt = 1, l_l = 0;

		for(int i = 0; i < p_l; i++) {
			if(P[i] == 'C') strt *= 2;
			if(P[i] == 'S') {
				total += strt;
				L[l_l++] = strt;
			}
		}

		int i = l_l-1, cnt = 0;
		while(total > D && L[i] != 1) {
			while(L[i] == L[i-1]) i--;
			total -= L[i] / 2;
			L[i] /= 2;
			i = l_l-1;
			cnt++;
		}

		printf("Case #%d: ", ++kase);
		if(total > D) puts("IMPOSSIBLE");
		else printf("%d\n", cnt);
	}

	return 0;
}
