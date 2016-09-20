#include<stdio.h>
const int maxn = 100000;
int main()
{
	int t, stk[maxn], tra[maxn];
	scanf("%d", &t);
	while(t--) {
		int n, top = -1; 
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &tra[i]);

		int i = n-1;
		while(n != 0)
			if((top < 0 || stk[top] != n) && i >= 0) stk[++top] = tra[i--];
			else { if(stk[top] == n) top--; n--; }

		top != -1 ? printf("No") : printf("Yes");
		putchar('\n');
	}
	
	return 0;
}
