#include<cstdio>
#include<cstring>
#include<algorithm>
using std::swap;

char puzzle[10][10];
struct blank {
	int r, c; //row, col
}b;

int main()
{
	int kase = 0;
	while(1) {
		for(int r = 1; r <= 5; r++) {
			fgets(puzzle[r]+1, 7, stdin);
			if(puzzle[r][1] == 'Z') return 0;

			for(int c = 1; c <= 5; c++) if(puzzle[r][c] == ' ') {
				b.r = r;
				b.c = c;
			}
		}

		char op;
		int illegal = 0;
		while((op = getchar()) && op != '0') {
			if(illegal || op == '\n') continue;

			int r = b.r, c = b.c;
			int newr, newc;
			if(op == 'A') { newr = r-1; newc = c; }
			if(op == 'B') { newr = r+1; newc = c; }
			if(op == 'R') { newr = r; newc = c+1; }
			if(op == 'L') { newr = r; newc = c-1; }
			if(newr < 1 || newr > 5 || newc < 1 || newc > 5) { illegal = 1; continue; }

			swap(puzzle[newr][newc], puzzle[r][c]);
			b.r = newr; b.c = newc;
		}

		printf("Puzlle #%d:\n", ++kase);
		if(illegal) puts("This puzzle has no final configuration.");
		else for(int r = 1; r <= 5; r++) {
			for(int c = 1; c <= 5; c++) printf("%c ", puzzle[r][c]);
			putchar('\n');
		}
	}

	return 0;
}
