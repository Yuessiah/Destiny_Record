#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e3 + 10;

int n, p[maxn];

int main()
{
  scanf("%d", &n);

  int a, b = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    p[i] = a - b;
    b = a;
  }

  vector<int> ans;
  for(int i = 1; i <= n; i++) {
    bool ok = true;
    for(int j = 0; j < n; j++)
      if(p[j] != p[j%i]) { ok = false; break; }

    if(ok) ans.push_back(i);
  }

  printf("%d\n", (int)ans.size());
  for(auto l: ans) printf("%d ", l);

  return 0;
}
