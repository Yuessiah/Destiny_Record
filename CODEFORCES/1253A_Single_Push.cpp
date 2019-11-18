#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int t, n, a[maxn], b;

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    vector<int> d;
    for(int i = 0; i < n; i++) {
      scanf("%d", &b);
      d.push_back(b-a[i]);
    }

    int i = 0;
    for(; d[i] == 0 && i < n; i++);
    for(int x = d[i]; x > 0 && d[i] == x && i < n; i++);
    for(; d[i] == 0 && i < n; i++);
    puts(i==n? "YES" : "NO");
  }

  return 0;
}
