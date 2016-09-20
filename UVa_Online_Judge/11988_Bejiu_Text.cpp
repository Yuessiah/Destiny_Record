#include<stdio.h>
const int MAXN = 100010;

char s[MAXN], f[MAXN], r[MAXN];
bool fr;
int fc, fc;

int findBracket(int &i) { for(; s[i] != '\0' && s[i] != '[' && s[i] != ']'; i++); }

int main()
{
	while(~scanf("%s", s)) {
		fr = 1;
		fc = rc = 0;
		for(int i = 0; s[i] != '\0'; i++) {
			char ch = s[i];
			if(ch == '[') fr = 0;
			else if(ch == ']') fr = 1;
			else {
				if(fr) r[rc++] = ch;
				else {
					int j = i;
					findBracket(i);
					for(int k = i-1; k >= j; k--) f[fc++] = s[k];
					i--;
				}
			}
		}

		if(fc) for(int i = fc-1; i >= 0; i--) printf("%c", f[i]);
		if(rc) for(int i = 0; i < rc; i++) printf("%c", r[i]);
		putchar('\n');
	}

	return 0;
}
