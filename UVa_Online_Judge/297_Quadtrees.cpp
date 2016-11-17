#include<stdio.h>
#include<string.h>
const int len = 32;

char qtree[1<<11]; //1<<11 is total of nodes
bool image[len][len];
int pixel;

void coat(int& cur, int row, int col, int width)
{
	if(qtree[cur] == 'p') {
		coat(++cur, row,         col+width/2, width/2);
		coat(++cur, row,         col,         width/2);
		coat(++cur, row+width/2, col,         width/2);
		coat(++cur, row+width/2, col+width/2, width/2);
	} else if(qtree[cur] == 'f') for(int r = row; r < row+width; r++) {
		for(int c = col; c < col+width; c++) if(!image[r][c]) {
			image[r][c] = 1;
			pixel++;
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	while(N--) {
		pixel = 0;
		memset(image, 0, sizeof(image));

		for(int i = 0; i < 2; i++) {
			scanf("%s", qtree);
			int cur = 0;
			coat(cur, 0, 0, len);
		}

		printf("There are %d black pixels.\n", pixel);
	}

	return 0;
}
