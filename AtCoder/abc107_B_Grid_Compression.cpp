#include<cstdio>
#include<cstring>

int const maxn = 110;

bool ver[maxn], hor[maxn];
int H, W;
char G[maxn][maxn];

int main()
{
  memset(ver, false, sizeof(ver));
  memset(hor, false, sizeof(hor));

  scanf("%d%d", &H, &W);

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      scanf(" %c", &G[i][j]);
      if(G[i][j] == '#') ver[j] = true;
      if(G[i][j] == '#') hor[i] = true;
    }
  }

  for(int i = 0; i < H; i++) {
    if(!hor[i]) continue;
    for(int j = 0; j < W; j++) if(ver[j]) printf("%c", G[i][j]);
    putchar('\n');
  }

  return 0;
}
