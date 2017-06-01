#include<cstdio>
#include<cstring>

int main()
{
	int T;
	char s[111];
	scanf("%d", &T);

	while(T--) {
		scanf("%s", s);

		int len = strlen(s);
		for(int i = 0; i < len; i++) {
			if(s[i] == 'm' && s[i-1] == 's') s[i-1] = 0;
			else if(s[i] == 'm' && s[i+1] == 's') s[i+1] = 0;
		}

		int mc = 0, sc = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == 'm') mc++;
			if(s[i] == 's') sc++;
		}

		if(mc > sc) puts("mongooses");
		if(sc > mc) puts("snakes");
		if(sc == mc) puts("tie");
	}

	return 0;
}
