#include<stdio.h>
#include<string.h>
const int maxn = 130;
const int maxw = 50;

char s1[maxn][maxw], s2[maxn][maxw];
int dp[maxn][maxn], n1, n2;

void LCS()
{
	for(int i = 0; i < n1; i++) dp[i][0] = 0;
	for(int j = 0; j < n2; j++) dp[0][j] = 0;

	for(int i = 1; i < n1; i++)
		for(int j = 1; j < n2; j++) {
			if(!strcmp(s1[i], s2[j])) dp[i][j] = dp[i-1][j-1] + 1;
			else {
				if(dp[i-1][j] < dp[i][j-1]) dp[i][j] = dp[i][j-1];
				else dp[i][j] = dp[i-1][j];
			}
		}
}

void print_LCS(int i, int j)
{
	if(!dp[i][j]) return;

	int y = i-1;
	while(dp[i][j] == dp[y][j]) y--;
	i = y+1;

	int x = j-1;
	while(dp[i][j] == dp[i][x]) x--;
	j = x+1;

	print_LCS(y, x);
	if(dp[i][j] != 1) putchar(' ');
	printf("%s", s1[i]);
}

int main()
{
	while(1) {
		char word[maxw];
		n1 = n2 = 1;

		int eof;
		while(~(eof = scanf("%s", word)) && word[0] != '#') strcpy(s1[n1++], word);
		if(eof == EOF) break;
		while(scanf("%s", word) && word[0] != '#') strcpy(s2[n2++], word);

		LCS();
		/*
		printf("    "); for(int i = 0; i < n2; i++) printf("%2d ", i);
		putchar('\n');
		for(int i = 0; i < n1; i++) {
			printf("%2d| ", i);
			for(int j = 0; j < n2; j++) printf("%2d ", dp[i][j]);
			putchar('\n');
		}
		*/
		print_LCS(n1-1, n2-1);
		putchar('\n');
	}

	return 0;
}
