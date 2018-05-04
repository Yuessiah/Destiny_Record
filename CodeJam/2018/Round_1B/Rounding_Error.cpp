#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

long N, L, C, no_round[maxn], b[maxn];

double rate() {
	return ((double)C/N) * 100;
}

bool ok() {
	return ((long)(rate()*10))%10 >= 5;
}

bool cmp(const long &A, const long &B) {
	return ((long)(((double)A/N)*1000))%10 >= ((long)(((double)B/N)*1000))%10;
}

void mergesort(int l, int r) {
  if (r-l <= 1) return;

  int m = l + (r-l)/2;
  mergesort(l, m);
  mergesort(m, r);

  int p = l, q = m, i = l;
  memcpy(b+l, no_round+l, (r-l)*sizeof(long));
  while (i < r) {
    if (q == r || (p != m && cmp(b[p], b[q])))
      no_round[i++] = b[p++];
    else
      no_round[i++] = b[q++];
  }
}

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		long res = 0, ans = 0, size = 0;

		scanf("%ld%ld", &N, &L);

		for(int i = 0; i < L; i++) {
			scanf("%ld", &C); res += C;
			if(ok()) ans += rate()+1;
			else no_round[size++] = C;
		}

		mergesort(0, size);

		/*
		for(int i = 0; i < size; i++) printf("%ld ", no_round[i]);
		putchar('\n');
		*/

		int big = 0;
		C = (big<size)? no_round[big++] : 0;

		for(int i = 0; i < (N-res); i++) {
			C++;
			if(ok()) {
				ans += rate()+1;
				C = (big<size)? no_round[big++] : 0;
			}
		}

		ans += rate();
		for(int i = big; i < size; i++) {
			C = no_round[i];
			ans += rate();
		}

		printf("Case #%d: %ld\n", ++kase, ans);
	}

	return 0;
}
