#include<cstdio>
#include<cstring>
const int maxn = 1e5 + 10;
const int INF = 0x7fffffff;

int n;
char c[2][maxn];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int cnt = 0;
		bool hor[2] = {};

		scanf("%d", &n);
		for(int i = 0; i < 2; i++) scanf(" %s", c[i]);

		for(int j = 0; j < n; j++) {
			if(c[0][j] == '*') hor[0] = 1;
			if(c[1][j] == '*') hor[1] = 1;
		}

		if(hor[0] && hor[1]) {
			int k, s; //start flag
			int num1, num2;
			for(int i = 0; i < n; i++) if(c[0][i] == '*') { num1 = i; break; }
			for(int i = 0; i < n; i++) if(c[1][i] == '*') { num2 = i; break; }
			if(num1 <= num2) { k = 0; s = num1; }
			else { k = 1; s = num2; }

			while(1) {
				if(c[k][s+1] == '*') {
					cnt++; s++;
				} else if(c[k^1][s] == '*') {
					cnt++;
					int i;
					num1 = num2 = INF;
					for(i = s+1; i < n; i++) if(c[0][i] == '*') { num1 = i; break; }
					for(i = s+1; i < n; i++) if(c[1][i] == '*') { num2 = i; break; }
					if(num1 == INF && num2 == INF) { cnt--; break; }
					if(num1 <= num2) { k = 0; s = num1; }
					else { k = 1; s = num2; }
				} else s++;
				if(s == n-1) break;
			}

			printf("%d\n", cnt+1);
		} else {
			if(hor[0]) for(int i = 0; i < n; i++) if(c[0][i] == '*') cnt++;
			if(hor[1]) for(int i = 0; i < n; i++) if(c[1][i] == '*') cnt++;
			if(cnt == 0) puts("0");
			else printf("%d\n", cnt-1);
		}
	}

	return 0;
}
