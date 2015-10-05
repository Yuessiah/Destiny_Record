#include<stdio.h>

const int submatrix[9][9] = {
	{0, 0, 0, 1, 1, 1, 2, 2, 2},
	{0, 0, 0, 1, 1, 1, 2, 2, 2},
	{0, 0, 0, 1, 1, 1, 2, 2, 2},
	{3, 3, 3, 4, 4, 4, 5, 5, 5},
	{3, 3, 3, 4, 4, 4, 5, 5, 5},
	{3, 3, 3, 4, 4, 4, 5, 5, 5},
	{6, 6, 6, 7, 7, 7, 8, 8, 8},
	{6, 6, 6, 7, 7, 7, 8, 8, 8},
	{6, 6, 6, 7, 7, 7, 8, 8, 8}
};
char map[9][9];

bool rowtest(int r, int n)
{
	for(int c = 0; c < 9; c++)
		if(map[r][c] == n+'0') return 0;
	return 1;
}
bool coltest(int c, int n)
{
	for(int r = 0; r < 9; r++)
		if(map[r][c] == n+'0') return 0;
	return 1;
}
bool matrixtest(int m, int n)
{
	for(int k = submatrix[m][0]; k - submatrix[m][0] != 3; k++)
		for(int i = m%3 * 3; i - (m%3 * 3) != 3; i++)
			if(map[k][i] == n+'0') return 0;
	return 1;
}
bool dfs(int r, int c)
{
	for(int i = 1; i <= 9; i++) {
		int m = submatrix[r][c];
		if(rowtest(r, i) && coltest(c, i) && matrixtest(m, i)) {
			map[r][c] = i+'0';

			bool bk = 0;
			for(int a = 0; !bk && a < 9; a++)
				for(int b = 0; !bk && b < 9; b++)
					if(map[a][b] == '.') if(dfs(a, b)) return 1; else bk = 1;
			if(!bk) return 1;
		}
		map[r][c] = '.';
	}
	return 0;
}

int main() {
	for(;;) {
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++) {
				int c = getchar(); if(c == 'e') return 0;
				map[i][j] = c;
			}
		getchar();

		bool ok = 1;
		for(int i = 0; ok && i < 9; i++)
			for(int j = 0; ok && j < 9; j++) if(map[i][j] != '.') {
				int n = map[i][j] - '0';
				map[i][j] = '\0';
				if(!(rowtest(i, n) && coltest(j, n) && matrixtest(submatrix[i][j], n))) ok = 0;
				map[i][j] = n + '0';
			}
		if(ok) {
			bool bk = 0;
			for(int i = 0; !bk && i < 9; i++)
				for(int j = 0; !bk && j < 9; j++)
					if(map[i][j] == '.') {
						if(dfs(i, j)) for(int k = 0; k < 9; k++)
							for(int l = 0; l < 9; l++) printf("%c", map[k][l]);
						else ok = 0;

						bk = 1;
					}
		}
		if(!ok) printf("No solution.");
		putchar('\n');
	}
}
