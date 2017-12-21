#include<cstdio>
#include<cstring>
const int maxs = 1e6 + 10;

char w[maxs], t[maxs];
int pi[maxs];

void faliure()
{
	int m = strlen(w);
	pi[0] = pi[1] = 0;

	for(int i = 1; i < m; i++) {
		int j = pi[i];
		while(j && w[i] != w[j]) j = pi[j];
		pi[i+1] = (w[i] == w[j])? j+1 : 0;
	}

	/*
	for(int i = 0; i < m; i++) printf("%d ", pi[i]);
	putchar('\n');
	*/
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
	//while(scanf("%s", w)) faliure();
	int T;
	scanf("%d", &T);

	while(T--) {
		scanf("%s%s", w, t);
		faliure();
		solve();
	}

	return 0;
}
