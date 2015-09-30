#include<stdio.h>
const int MAXLV = 6, MAXK = 13;

int k, lucky[MAXK], stack[MAXLV];

void output()
{
	for(int i = 0; i < MAXLV; i++) {
		printf("%d", stack[i]);
		if(i < MAXLV-1) putchar(' ');
	} putchar('\n');
}
void dfs(int depth, int last)
{
	if(depth == MAXLV) output();
	else for(int i = last+1; i < k; i++) {
		stack[depth] = lucky[i];
		dfs(depth+1, i);
	}
}

int main()
{
	bool ok = 0;
	while(scanf("%d", &k) && k) {
		if(ok) putchar('\n');
		else ok = 1;

		for(int i = 0; i < k; i++) scanf("%d", &lucky[i]);
		dfs(0, -1);
	}
 
	return 0;
}
