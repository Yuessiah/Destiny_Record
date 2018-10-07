#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, V[maxn], I[maxn];
bool w[maxn];

int main()
{
  scanf("%d", &n);

  for(int i = 1; i <= n; i++) {
    scanf("%d", &V[i]);
    I[V[i]] = i;
  }

  memset(w, false, sizeof(w));
  for(int i = n-1; i >= 1; i--) {
    for(int m = I[i]%V[I[i]]; m <= n; m+=V[I[i]])
      if(V[m] > V[I[i]] && !w[m]) { w[I[i]] = true; break; }
  }

  for(int i = 1; i <= n; i++) printf("%c", w[i]? 'A' : 'B');

  return 0;
}
