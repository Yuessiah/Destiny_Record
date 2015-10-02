#include<stdio.h>
#include<string.h>
const int MAXLEN = 50000;
char s[MAXLEN+1];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);

		int max = 0;
		for(int i = 1, len = strlen(s); i < len; i++)
			for(int par = 0; par < 2; par++) {
				int c = par ? 0 : 1;
				for(int j = 1; i-j >= 0 && i+j-par < len; j++) {
					if(s[i-j] == s[i+j-par]) c += 2; else break;
				}
				if(c > max) max = c;
			}

		printf("%d\n", max);
	}
	return 0;
}
