#include<stdio.h>
#include<string.h>

int score[8][8], max, row[8];

bool check(int r, int c)
{
	for(int i = 0; i < c; i++) {
		if(row[i] == r || (r+c) == (row[i]+i) || (r-c) == (row[i]-i)) return false;
	}
	return true;
}

void solve(int c, int sum)
{
	if(c == 8) {
		if(sum > max) max = sum;
	} else for(int r = 0; r < 8; r++) if(check(r, c)) {
		row[c] = r;
		solve(c+1, sum+score[r][c]);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(row, 0, sizeof(row));

		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++) scanf("%d", &score[i][j]);

		max = 0;
		solve(0, 0);

		printf("%5d\n", max);
	}

	return 0;
}
