#include<bits/stdc++.h>
using namespace std;

const int maxs = 1e2 + 10;

int main()
{
	char s[maxs];
	scanf("%s", s);

	int n = strlen(s), cnt = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			for(int k = j+1; k < n; ++k)
				if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') ++cnt;
	printf("%d\n", cnt);

	return 0;
}
