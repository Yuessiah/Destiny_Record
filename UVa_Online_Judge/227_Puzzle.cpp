#include<cstdio>
#include<cstring>
#include<algorithm>
using std::swap;

char puzzle[10][10];
struct blank {
	int r, c; //row, col
}b;

void printResult()
{
	for(int r = 1; r <= 5; r++) {
		for(int c = 1; c <= 5; c++) {
			printf("%c", puzzle[r][c]);
			if(c < 5) putchar(' ');
		}
		putchar('\n');
	}
}

int main()
{
	int kase = 0;
	while(1) {
		for(int r = 1; r <= 5; r++) {
			for(int c = 1; c <= 5; c++) {
				puzzle[r][c] = getchar();
				if(puzzle[1][1] == 'Z') return 0;
				if(puzzle[r][c] == ' ') {
					b.r = r;
					b.c = c;
				}
			}
			getchar();
		}

		char op;
		int illegal = 0;
		while((op = getchar()) && op != '0') {
			if(illegal || op == '\n') continue;

			int r = b.r, c = b.c;
			int newr, newc;
			switch(op) {
				case 'A':
					newr = r-1; newc = c;
					break;
				case 'B':
					newr = r+1; newc = c;
					break;
				case 'R':
					newr = r; newc = c+1;
					break;
				case 'L':
					newr = r; newc = c-1;
					break;
				default: illegal = 1;
			}
			if(newr < 1 || newr > 5 || newc < 1 || newc > 5) { illegal = 1; continue; }

			swap(puzzle[newr][newc], puzzle[r][c]);
			b.r = newr; b.c = newc;
		}
		getchar();

		if(kase) putchar('\n');
		printf("Puzzle #%d:\n", ++kase);
		if(illegal) puts("This puzzle has no final configuration.");
		else printResult();
	}

	return 0;
}
