#include<bits/stdc++.h>
using namespace std;

int const maxn = 110;

int q, n, a[maxn];

int main()
{
  scanf("%d", &q);

  while(q--) {
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);

    bool used[maxn] = {};

    for(int k = 0; k < n; k++)
      for(int i = n-2; i >= 0; i--) {
        if(a[i] <= a[i+1] || used[i]) continue;

        used[i] = true;
        swap(a[i], a[i+1]);
      }

    for(int k = 0; k < n; k++) printf("%d ", a[k]);
    putchar('\n');
  }

  return 0;
}
