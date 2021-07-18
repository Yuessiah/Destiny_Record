#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;
int constexpr maxa = 25e5 + 10;

int n, a[maxn];

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  pair<int, int> vis[maxa*2] {};
  for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++) {
      int sum = a[i] + a[j];
      auto& [_i, _j] = vis[sum];

      if(!_i) _i = i, _j = j;
      else if(_i != i && _i != j && _j != i && _j != j) {
        puts("YES");
        printf("%d %d %d %d\n", _i, _j, i, j);

        return 0;
      }
    }

  puts("NO");

  return 0;
}
