#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
const int maxh = 200 + 10;
const int maxw = 50 + 10;
const char hieroglyph[6] = { 'W', 'A', 'K', 'J', 'S', 'D' };
const int dr[4] = { 1, 0, -1, 0 };
const int dc[4] = { 0, -1, 0, 1 };

int h, w;
int image[maxh][maxw*4];
char input[maxh][maxw];

char* hex_to_bin(char hex)
{
	int i = 4, h;
	char* bin = (char*)malloc(sizeof(char)*4);
	if(isdigit(hex)) h = hex - '0';
	else h = hex - 'a' + 10;

	for(int b = 1; b <= 1<<3; b <<= 1) {
		if(b & h) *(bin + --i) = '1';
		else *(bin + --i) = '0';
	}
	return bin;
}

void floodfill(int r, int c, int want, int id)
{
	if(!(r >= 0 && r < h+2 && c >= 0 && c < w*4+2)) return;
	if(image[r][c] != want) return;
	image[r][c] = id;

	for(int d = 0; d < 4; d++) floodfill(r+dr[d], c+dc[d], want, id);
}

void normalization()
{
	for(int r = 0; r < h; r++)
		for(int c = 0; c < w; c++) {
			char bin[5]; strcpy(bin, hex_to_bin(input[r][c]));
			for(int k = 0; k < 4; k++) image[r+1][c*4+k+1] = (bin[k] == '1')? 1 : 0;
		}

	int ok = 0;
	for(int r = 0; r < h+2; r++) {
		for(int c = 0; c < w*4+2; c++) if(image[r][c] == 0) {
			floodfill(r, c, 0, 9);
			ok = 1; break;
		}
		if(ok) break;
	}
}

void hole_count(int r, int c, int& hole)
{
	if(!(r >= 0 && r < h+2 && c >= 0 && c < w*4+2)) return;
	if(image[r][c] == 9) return;
	if(image[r][c] == 0) {
		hole++;
		floodfill(r, c, 0, 1);
	}
	image[r][c] = 9;

	for(int d = 0; d < 4; d++) hole_count(r+dr[d], c+dc[d], hole);
}

int main()
{
	int kase = 0;
	while(scanf("%d%d", &h, &w) == 2 && h && w) {
		int cnt = 0;
		char result[maxw*4];
		memset(image, 0, sizeof(image));

		for(int i = 0; i < h; i++) scanf("%s", input[i]);
		normalization();

		for(int r = 0; r < h+2; r++)
			for(int c = 0; c < w*4+2; c++)
				if(image[r][c] == 1) {
					int hole = 0; hole_count(r, c, hole);
					if(hole <= 5) result[cnt++] = hieroglyph[hole];
				}

		std::sort(result, result+cnt);
		printf("Case %d: ", ++kase);
		for(int i = 0; i < cnt; i++) putchar(result[i]);
		putchar('\n');
	}

	return 0;
}
