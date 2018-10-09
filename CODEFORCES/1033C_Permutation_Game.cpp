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
  for(int a = n-1; a >= 1; a--) {
    for(int m = I[a]%a; m <= n; m+=a)
      if(V[m] > a && !w[m]) { w[I[a]] = true; break; }
  }

  for(int i = 1; i <= n; i++) printf("%c", w[i]? 'A' : 'B');

  return 0;
}
