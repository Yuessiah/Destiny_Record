#include<cstdio>
#include<cstring>
const int maxn = 1000000 + 10000 + 100;

char w[maxn], t[maxn];
int pi[maxn];

void faliure(char p[maxn])
{
	int m = strlen(p);
	pi[0] = pi[1] = 0;

	for(int i = 1; i < m; i++) {
		int j = pi[i];
		while(j && p[i] != p[j]) j = pi[j];
		pi[i+1] = (p[i] == p[j])? j+1 : 0;
	}

	for(int i = 0; i < m; i++) printf("%d ", pi[i]);
	putchar('\n');
}

void solve()
{
	int cnt = 0, j = 0, n = strlen(t), m = strlen(w);
	for(int i = 0; i < n; i++) {
		while(j && w[j] != t[i]) j = pi[j];
		if(w[j] == t[i]) j++;
		if(j == m) { cnt++; j = pi[j]; }
	}

	printf("%d\n", cnt);
}

int main()
{
	scanf("%s", w);
	faliure(w);
	int T;
	scanf("%d", &T);

	while(T--) {
		scanf("%s%s", w, t);
		faliure(w);
		solve();
	}

	return 0;
}
