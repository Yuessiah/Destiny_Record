#include<bits/stdc++.h>
using namespace std;

int const maxn = 111;

int a[maxn], q, n;

int main()
{
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    sort(a, a+n);

    bool two = false;
    for(int i = 1; i < n; i++) if(a[i]-a[i-1] == 1) two = true;
    puts(two? "2" : "1");
  }

  return 0;
}
