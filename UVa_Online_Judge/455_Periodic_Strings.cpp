#include<cstdio>
#include<cstring>
const int maxn = 1000000 + 100;

int pi[maxn];

void solve(char s[maxn])
{
	int m = strlen(s), cur = -1;
	pi[0] = -1;
	for(int i = 1; i < m; i++) {
		while(~cur && s[cur+1] != s[i]) cur = pi[cur];
		if(s[cur+1] == s[i]) cur++;
		pi[i] = cur;
	}

	/*
		 for(int i = 0; i < m; i++) printf("%d ", pi[i]);
		 putchar('\n');
		 */

	if(m%(m-cur-1) == 0) printf("%d\n", m-cur-1);
	else printf("%d\n", m);
}

int main()
{
	int T;
	char s[maxn];
	scanf("%d", &T);

	while(T--){
		scanf("%s", s);
		solve(s);
		if(T) putchar('\n');
	}

	return 0;
}
