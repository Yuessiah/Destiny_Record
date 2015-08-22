#include<stdio.h>
char bb[1<<15][17];

int main()
{
	bb[0][0] = bb[0][1] = 'O';
	int l = 1, w = 2;
	printf("O\n\n");
	printf("O\nO\n");

	int T = 15;
	while(T--) {
		putchar('\n');
		for(int i = 0; i < l; i++)
			for(int j = 0; j < w; j++) {
				bb[l+i][j+1] = bb[i][j];
			}
		l *= 2; w++;

		int x = l;
		for(int i = w-1; i >= 0; i--, x/=2) {
			for(int j = l-1; j >= 0; j--) {
				if(j == x-2) break;
				if(bb[j][i] != 'O') putchar('.');
				else putchar('O');
			}
			putchar('\n');
		}
	}
	return 0;
}
