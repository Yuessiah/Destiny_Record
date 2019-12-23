#include<bits/stdc++.h>
using namespace std;

int const maxr = 110;
char const label[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";

int T, r, c, k;
char farm[maxr][maxr];

int main()
{
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d%d", &r, &c, &k);

    int rice = 0;
    for(int y = 0; y < r; y++)
      for(int x = 0; x < c; x++) {
        scanf(" %c", &farm[y][x]);
        rice += farm[y][x] == 'R';
      }

    int m = rice%k, q = rice/k + (m? !!(m--) : 0), chicken = 0;

    for(int y = 0; y < r; y++) {
      string cell;
      for(int i = 0; i < c; i++) {
        int x = (y&1)? c-1-i : i;

        if(farm[y][x] == 'R') {
          if(!q) q = rice/k + (m? !!(m--) : 0), chicken++;
          q--;
        }

        cell += label[chicken];
      }
      if(y&1) reverse(cell.begin(), cell.end());

      cout << cell << endl;
    }
  }

  return 0;
}
