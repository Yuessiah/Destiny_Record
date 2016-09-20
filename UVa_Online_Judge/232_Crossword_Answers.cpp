#include<stdio.h>
#include<string.h>
const int maxn = 10;

int r, c;
char puz[maxn+10][maxn+10];
int flag[maxn+10][maxn+10];

void across_print()
{
	int ok = 1;
	for(int i = 0; i < r; i++) {
		int p = 0;
		while(p < c) {
			if((!p || puz[i][p-1] == '*') && puz[i][p] != '*') printf("\n%3d.", flag[i][p]);
			if(puz[i][p] != '*') putchar(puz[i][p]);
			p++;
		}
	}
	putchar('\n');
}

void down_print()
{
	for(int i = 0; i < r; i++) {
		int p = 0;
		while(p < c) {
			if((!i || puz[i-1][p] == '*') && puz[i][p] != '*') {
				printf("\n%3d.", flag[i][p]);
				int j = i;
				while(puz[j][p] != '*' && j < r) putchar(puz[j++][p]);
			}
			p++;
		}
	}
	putchar('\n');
}

void input()
{
	int n = 0;
	for(int i = 0; i < r; i++) {
		scanf("%s", puz[i]);
		for(int j = 0; j < c; j++) 
			if((!i || !j || puz[i-1][j] == '*' || puz[i][j-1] == '*') && puz[i][j] != '*') flag[i][j] = ++n;
	}
}

int main()
{
	int kase = 0;
	while(scanf("%d%d", &r, &c) && r) {
		memset(flag, 0, sizeof(flag));
		input();

		if(kase) putchar('\n');
		printf("puzzle #%d:\n", ++kase);
		printf("Across"); across_print();
		printf("Down"); down_print();
	}

	return 0;
}
