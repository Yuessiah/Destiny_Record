#include<stdio.h>
const int maxn = 1000000;
int main()
{
	int T, n, s[maxn], a[maxn];
	scanf("%d", &T);
	while(T--) {
		int top = -1;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);

		int cnt = 0;
		while(n--) {
			if(top == -1) s[++top] = a[n];
			else {
				for(int i = top; i >= 0; i--) {
					if(s[i] < a[n]) top--;
					cnt++;
					if(s[i] > a[n]) break;
				} 

				s[++top] = a[n];
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
