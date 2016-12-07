#include<stdio.h>
#include<string.h>
const int maxw = 100;

int sum[maxw];

void build(int pos)
{
	int v;
	scanf("%d", &v);
	if(v == -1) return;
	sum[pos] += v;
	build(pos-1); build(pos+1);
}

bool input()
{
	int v;
	scanf("%d", &v);
	if(v == -1) return false;
	memset(sum, 0, sizeof(sum));
	int pos = maxw / 2;
	sum[pos] = v;
	build(pos-1); build(pos+1);
	return true;
}

int main()
{
	int kase = 0;
	while(input()) {
		int pos = 0;
		while(sum[pos] == 0) pos++;
		printf("Case %d:\n", ++kase);
		do {
			printf("%d", sum[pos]);
			if(sum[++pos] == 0) break;
			putchar(' ');
		}while(1);
		printf("\n\n");
	}

	return 0;
}
