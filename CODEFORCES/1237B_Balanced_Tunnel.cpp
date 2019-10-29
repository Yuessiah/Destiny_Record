#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, a, b, ord[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    ord[a] = i;
  }

  vector<int> out;
  for(int i = 0; i < n; i++) {
    scanf("%d", &b);
    out.push_back(ord[b]);
  }

  int cnt = 0, mn = n+1;
  while(out.size()) {
    if(mn > out.back()) mn = out.back();
    if(out.back() > mn) cnt++;
    out.pop_back();
  }

  printf("%d\n", cnt);

  return 0;
}
