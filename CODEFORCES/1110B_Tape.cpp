#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, m, k, b[maxn];
priority_queue<int, vector<int>, greater<int> > seg;

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    if(i > 0) seg.push(b[i]-b[i-1]-1);
  }

  int ans = n;
  while(n-- > k) ans += seg.top(), seg.pop();
  printf("%d\n", ans);

  return 0;
}
