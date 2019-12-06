#include<bits/stdc++.h>
using namespace std;

int t, a[3];

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d", &a[0], &a[1], &a[2]);

    sort(a, a+3);
    int d = a[2] - a[1];
    a[1] += min(d, a[0]);
    a[0] -= min(d, a[0]);
    printf("%d\n", min(a[1], a[2]) + a[0]/2);
  }

  return 0;
}
