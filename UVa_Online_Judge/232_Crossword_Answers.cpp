#include<cstdio>

int const maxn = 20;

int r, c, flag[maxn][maxn];
char puz[maxn][maxn];

bool across_head(int i, int j)
  { return !j || puz[i][j-1] == '*'; }

bool down_head(int i, int j)
  { return !i || puz[i-1][j] == '*'; }

void across_print() {
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++) {
      if(across_head(i, j) && puz[i][j] != '*') printf("\n%3d.", flag[i][j]);
      if(puz[i][j] != '*') putchar(puz[i][j]);
    }
}

void down_print() {
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      if(down_head(i, j) && puz[i][j] != '*') {
        printf("\n%3d.", flag[i][j]);
        for(int k = i; puz[k][j] != '*' && k < r; k++) putchar(puz[k][j]);
      }
}

bool flag_position(int i, int j)
  { return (across_head(i, j) || down_head(i, j)) && puz[i][j] != '*'; }

int main()
{
  int kase = 0;
  while(scanf("%d%d", &r, &c) && r) {
    for(int i = 0; i < r; i++) scanf("%s", puz[i]);

    //preprocess
    int n = 0;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        if(flag_position(i, j)) flag[i][j] = ++n;
        else flag[i][j] = 0;

    //print answer
    if(kase) putchar('\n');
    printf("puzzle #%d:\n", ++kase);

    printf("Across");
    across_print();
    putchar('\n');

    printf("Down");
    down_print();
    putchar('\n');
  }

  return 0;
}
