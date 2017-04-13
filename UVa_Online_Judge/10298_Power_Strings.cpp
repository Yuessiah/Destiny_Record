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

	if(m%(m-cur-1)) puts("1");
	else printf("%d\n", m/(m-cur-1));
}

int main()
{
	char s[maxn];
	while(fgets(s, maxn, stdin)){
		s[strlen(s)-1] = '\0';
		if(s[0] == '.' && s[1] == '\0') break;

		if(strlen(s) == 0) puts("0");
		else solve(s);
	}
	return 0;
}
