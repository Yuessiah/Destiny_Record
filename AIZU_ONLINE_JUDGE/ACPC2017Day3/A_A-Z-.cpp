#include<cstdio>
#include<cstring>

int main()
{
	char s[111];

	while(~scanf("%s", s)) {
		int cnt = 0;
		char p = 'A'; // p := previous
		for(int i = 0, l = strlen(s); i < l; i++) {
			if(p >= s[i]) cnt++;
			p = s[i];
		}

		printf("%d\n", cnt);
	}

	return 0;
}
